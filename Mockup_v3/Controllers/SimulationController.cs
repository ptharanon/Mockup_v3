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
        public ActionResult UpdateGraph(String plot, String type, double param1, double param2, double param3, double param4)
        {
            double sample = 2 * Math.Pow(10, -5);
            double endtime = 2;
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            if (type == "Step")
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
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
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
            }
            else if (plotname == "outputSpeed")
            {
                full_signal = graphs.OutputSpeedTrace;
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
                }
            }
            return Json(new { signal = signal }, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public ActionResult Simulate(String motor)
        {
            SimulationResults results = new SimulationResults();
            List<List<List<double>>> output = results.startSimulation(graphs.InputSpeedTrace, graphs.InputTorqueTrace, graphs.InputTorqueTrace[0].Count);
            graphs.OutputCurrentTrace = output[0];
            graphs.OutputSpeedTrace = output[1];
            graphs.OutputTorqueTrace = output[2];
            graphs.OutputVoltageTrace = output[3];

            return Json(new { done = true }, JsonRequestBehavior.AllowGet);
        }

        public void ExportDataToCsv()
        {

            StringWriter sw = new StringWriter();

            sw.WriteLine("\"Time\",\"Stator Current\",\"Torque\",\"Speed\",\"DC Voltage\"");

            Response.ClearContent();
            Response.AddHeader("content-disposition", "attachment;filename=Simulation.csv");
            Response.ContentType = "text/csv";
            
            for (int i = 0; i < graphs.OutputCurrentTrace.Count; i++)
            {
                sw.WriteLine(string.Format("\"{0}\",\"{1}\",\"{2}\",\"{3}\",\"{4}\"",
                                            graphs.OutputCurrentTrace[0][i],
                                            graphs.OutputCurrentTrace[1][i],
                                            graphs.OutputSpeedTrace[1][i],
                                            graphs.OutputTorqueTrace[1][i],
                                            graphs.OutputVoltageTrace[1][i]));
            }

            Response.Write(sw.ToString());
            Response.End();
        }
    }
}