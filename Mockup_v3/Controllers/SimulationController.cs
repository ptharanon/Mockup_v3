using LumenWorks.Framework.IO.Csv;
using Mockup_v3.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Web;
using System.Web.Mvc;
using System.Web.Script.Serialization;
using System.Linq;
using MotorLibrary.Helper;
using MotorLibrary.Helper.ExternalModel;

namespace Mockup_v3.Controllers
{
    [Authorize]
    public class SimulationController : Controller
    {
        private static Graphs graphs = new Graphs();

        // GET: Simulation
        public ActionResult Index()
        {
            XMLReader readXML = new XMLReader();
            var data = readXML.RetrunListOfProducts();

            return View(data.ToList());
        }

        [HttpPost]
        public ActionResult UpdateGraph(String plot, String type, double param1, double param2, double param3, double param4, double endtime, double sample)
        {
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            if (type == "Constant")
            {
                signal = graphs.GenerateConstant(param1, sample, endtime);
            }
            else if (type == "Step")
            {
                signal = graphs.GenerateStep(param1, param2, param3, sample, endtime);
            }
            else if (type == "Ramp")
            {
                signal = graphs.GenerateRamp(param1, param2, param3, sample, endtime);
            }
            else if (type == "Sinusoid")
            {
                signal = graphs.GenerateSinusoid(param1, param2, param3, param4, sample, endtime);
            }
            if (plot == "inputSpeed")
            {
                graphs.InputSpeedTrace = signal;
            }
            else if (plot == "inputTorque")
            {
                graphs.InputTorqueTrace = signal;
            }

            return Json(new { done = true });
        }
        
        [HttpPost]
        public ActionResult Upload(HttpPostedFileBase file, String plotname)
        {
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());

            // Verify that the user selected a file
            if (file != null && file.ContentLength > 0)
            {
                Stream stream = file.InputStream;
                using (CsvReader csvReader = new CsvReader(new StreamReader(stream), true))
                {
                    string[] headers = csvReader.GetFieldHeaders();
                    while (csvReader.ReadNextRecord())
                    {
                        signal[0].Add(Double.Parse(csvReader[0]));
                        signal[1].Add(Double.Parse(csvReader[1]));
                    }
                }
            }
            if (plotname == "inputSpeed")
            {
                graphs.InputSpeedTrace = signal;
            }
            else if (plotname == "inputTorque")
            {
                graphs.InputTorqueTrace = signal;
            }

            return Json(new { done = true });
        }

        [HttpGet]
        public ActionResult GetPlotData(String plotname)
        {
            List<List<double>> full_signal = new List<List<double>>();
            List<List<double>> full_refsignal = new List<List<double>>();
            List<List<double>> signal = new List<List<double>>();
            List<List<double>> refsignal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            refsignal.Add(new List<double>());
            refsignal.Add(new List<double>());
            if (plotname == "inputSpeed")
            {
                full_signal = graphs.InputSpeedTrace;
            }
            else if (plotname == "inputTorque")
            {
                full_signal = graphs.InputTorqueTrace;
            }
            else if (plotname == "outputCurrent")
            {
                full_signal = graphs.OutputCurrentTrace;
            }
            else if (plotname == "outputTorque")
            {
                full_signal = graphs.OutputTorqueTrace;
                full_refsignal = graphs.OutputRefTorqueTrace;
            }
            else if (plotname == "outputSpeed")
            {
                full_signal = graphs.OutputSpeedTrace;
                full_refsignal = graphs.OutputRefSpeedTrace;
            }
            else if (plotname == "outputVoltage")
            {
                full_signal = graphs.OutputVoltageTrace;
            }
            float full_size = full_signal[0].Count;
            float MAX_SIZE = 30000;
            int scale_factor = (int)(full_size / MAX_SIZE) + 1;
            for (int i = 0; i < full_size; i++)
            {
                if (i % scale_factor == 0)
                {
                    signal[0].Add(full_signal[0][i]);
                    signal[1].Add(full_signal[1][i]);
                    if (full_refsignal.Count > 0)
                    {
                        refsignal[0].Add(full_refsignal[0][i]);
                        refsignal[1].Add(full_refsignal[1][i]);
                    }
                }
            }
            return Json(new { signal = signal, refsignal = refsignal }, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public ActionResult Simulate(String motor)
        {
            SimulationResults results = new SimulationResults();

            List<List<Double>> speed = graphs.InputSpeedTrace;
            List<List<Double>> torque = graphs.InputTorqueTrace;

            double sample1 = speed[0][1] - speed[0][0];
            double sample2 = torque[0][1] - torque[0][0];

            if (sample1 != sample2)
            {
                return Json(new { zoh = false, sm = false }, JsonRequestBehavior.AllowGet);
            }
            else
            {
                int speed_size = speed[0].Count;
                int torque_size = torque[0].Count;
                bool zohused = false;
                if (speed_size > torque_size)
                {
                    double zoh = torque[1][torque_size - 1];
                    for (int i=torque_size; i<speed_size; i++)
                    {
                        torque[0].Add(speed[0][i]);
                        torque[1].Add(zoh);
                    }
                    zohused = true;
                }
                if (torque_size > speed_size)
                {
                    double zoh = speed[1][speed_size - 1];
                    for (int i = speed_size; i < torque_size; i++)
                    {
                        speed[0].Add(torque[0][i]);
                        speed[1].Add(zoh);
                    }
                    zohused = true;
                }

                List<List<List<double>>> output = results.startSimulation(motor, speed, torque, speed_size);
                graphs.OutputCurrentTrace = output[0];
                graphs.OutputSpeedTrace = output[1];
                graphs.OutputRefSpeedTrace = output[2];
                graphs.OutputTorqueTrace = output[3];
                graphs.OutputRefTorqueTrace = output[4];
                graphs.OutputVoltageTrace = output[5];

                return Json(new { zoh = zohused, sm = true }, JsonRequestBehavior.AllowGet);
            }
        }

        public void ExportDataToCsv(string type)
        {
            StringWriter sw = new StringWriter();

            switch (type){

                case "Simulation":
                    sw.WriteLine("\"Time\",\"Stator Current\",\"Torque\",\"Speed\",\"DC Voltage\"");

                    Response.ClearContent();
                    Response.AddHeader("content-disposition", "attachment;filename=Simulation.csv");
                    Response.ContentType = "text/csv";

                    for (int i = 0; i < graphs.OutputCurrentTrace[0].Count; i++)
                    {
                        sw.WriteLine(string.Format("\"{0}\",\"{1}\",\"{2}\",\"{3}\",\"{4}\"",
                                                    graphs.OutputCurrentTrace[0][i],
                                                    graphs.OutputCurrentTrace[1][i],
                                                    graphs.OutputTorqueTrace[1][i],
                                                    graphs.OutputSpeedTrace[1][i],
                                                    graphs.OutputVoltageTrace[1][i]));
                    }

                    Response.Write(sw.ToString());
                    Response.End();
                    break;

                case "Stator Current":
                    sw.WriteLine("\"Time\",\"Stator Current\"");

                    Response.ClearContent();
                    Response.AddHeader("content-disposition", "attachment;filename=Current.csv");
                    Response.ContentType = "text/csv";

                    for (int i = 0; i < graphs.OutputCurrentTrace[0].Count; i++)
                    {
                        sw.WriteLine(string.Format("\"{0}\",\"{1}\"",
                                                    graphs.OutputCurrentTrace[0][i],
                                                    graphs.OutputCurrentTrace[1][i]));
                    }

                    Response.Write(sw.ToString());
                    Response.End();
                    break;

                case "Torque":
                    sw.WriteLine("\"Time\",\"Torque\"");

                    Response.ClearContent();
                    Response.AddHeader("content-disposition", "attachment;filename=Torque.csv");
                    Response.ContentType = "text/csv";

                    for (int i = 0; i < graphs.OutputCurrentTrace[0].Count; i++)
                    {
                        sw.WriteLine(string.Format("\"{0}\",\"{1}\"",
                                                    graphs.OutputCurrentTrace[0][i],
                                                    graphs.OutputTorqueTrace[1][i]));
                    }

                    Response.Write(sw.ToString());
                    Response.End();
                    break;

                case "Speed":
                    sw.WriteLine("\"Time\",\"Speed\"");

                    Response.ClearContent();
                    Response.AddHeader("content-disposition", "attachment;filename=Speed.csv");
                    Response.ContentType = "text/csv";

                    for (int i = 0; i < graphs.OutputCurrentTrace[0].Count; i++)
                    {
                        sw.WriteLine(string.Format("\"{0}\",\"{1}\"",
                                                    graphs.OutputCurrentTrace[0][i],
                                                    graphs.OutputSpeedTrace[1][i]));
                    }

                    Response.Write(sw.ToString());
                    Response.End();
                    break;

                case "DC Bus Voltage":
                    sw.WriteLine("\"Time\",\"DC Voltage\"");

                    Response.ClearContent();
                    Response.AddHeader("content-disposition", "attachment;filename=Voltage.csv");
                    Response.ContentType = "text/csv";

                    for (int i = 0; i < graphs.OutputCurrentTrace[0].Count; i++)
                    {
                        sw.WriteLine(string.Format("\"{0}\",\"{1}\"",
                                                    graphs.OutputCurrentTrace[0][i],
                                                    graphs.OutputVoltageTrace[1][i]));
                    }

                    Response.Write(sw.ToString());
                    Response.End();
                    break;
            }
        }
    }
}