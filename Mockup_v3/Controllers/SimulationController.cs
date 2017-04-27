using LumenWorks.Framework.IO.Csv;
using Mockup_v3.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Web;
using System.Web.Mvc;
using System.Web.Script.Serialization;

namespace Mockup_v3.Controllers
{
    [Authorize]
    public class SimulationController : Controller
    {
        private static Graphs graphs = new Graphs();

        // GET: Simulation
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult UpdateGraph(String plot, String type, double param1, double param2, double param3, double param4)
        {
            double sample = 2 * Math.Pow(10, -5);
            double endtime = 1;
            List<double[]> signal = new List<double[]>();
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
                graphs.InputSpeedPoints = signal;
            }
            else if (plot == "inputTorque")
            {
                graphs.InputTorquePoints = signal;
            }

            return Json(new { done = true });
        }
        
        [HttpPost]
        public ActionResult Upload(HttpPostedFileBase file, String plotname)
        {
            List<double[]> signal = new List<double[]>();

            // Verify that the user selected a file
            if (file != null && file.ContentLength > 0)
            {
                Stream stream = file.InputStream;
                using (CsvReader csvReader = new CsvReader(new StreamReader(stream), true))
                {
                    string[] headers = csvReader.GetFieldHeaders();
                    while (csvReader.ReadNextRecord())
                    {
                        signal.Add(new double[] { Double.Parse(csvReader[0]), Double.Parse(csvReader[1]) });
                    }
                }
            }
            if (plotname == "inputSpeed")
            {
                graphs.InputSpeedPoints = signal;
            }
            else if (plotname == "inputTorque")
            {
                graphs.InputTorquePoints = signal;
            }

            return Json(new { done = true });
        }

        [HttpGet]
        public ActionResult GetPlotData(String plotname)
        {
            List<double[]> full_signal = new List<double[]>();
            List<double[]> signal = new List<double[]>();
            int scale_factor = 100;
            if (plotname == "inputSpeed")
            {
                full_signal = graphs.InputSpeedPoints;
            }
            else if (plotname == "inputTorque")
            {
                full_signal = graphs.InputTorquePoints;
            }
            else if (plotname == "outputCurrent")
            {
                full_signal = graphs.OutputCurrentPoints;
            }
            else if (plotname == "outputTorque")
            {
                full_signal = graphs.OutputTorquePoints;
            }
            else if (plotname == "outputSpeed")
            {
                full_signal = graphs.OutputSpeedPoints;
            }
            else if (plotname == "outputVoltage")
            {
                full_signal = graphs.OutputVoltagePoints;
            }
            for (int i = 0; i < full_signal.Count; i++)
            {
                if (i % scale_factor == 0)
                {
                    signal.Add(full_signal[i]);
                }
            }
            return Json(new { signal = signal }, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public ActionResult Simulate(String motor)
        {
            SimulationResults results = new SimulationResults();
            List<List<double[]>> output = results.startSimulation(graphs.InputSpeedPoints, graphs.InputTorquePoints, graphs.InputTorquePoints.Count);
            graphs.OutputCurrentPoints = output[0];
            graphs.OutputSpeedPoints = output[1];
            graphs.OutputTorquePoints = output[2];
            graphs.OutputVoltagePoints = output[3];

            return Json(new { done = true }, JsonRequestBehavior.AllowGet);
        }

        public void ExportDataToCsv()
        {

            StringWriter sw = new StringWriter();

            sw.WriteLine("\"Time\",\"Input Speed\",\"Load Torque\",\"Stator Current\",\"Torque\",\"Speed\",\"DC Voltage\"");

            Response.ClearContent();
            Response.AddHeader("content-disposition", "attachment;filename=Simulation.csv");
            Response.ContentType = "text/csv";

            for (int i = 0; i < graphs.InputSpeedPoints.Count; i++)
            {
                sw.WriteLine(string.Format("\"{0}\",\"{1}\",\"{2}\",\"{3}\",\"{4}\",\"{5}\",\"{6}\"",
                                           graphs.InputSpeedPoints[i][0],
                                           graphs.InputSpeedPoints[i][1],
                                           graphs.InputTorquePoints[i][1],
                                           graphs.OutputCurrentPoints[i][1],
                                           graphs.OutputSpeedPoints[i][1],
                                           graphs.OutputTorquePoints[i][1],
                                           graphs.OutputVoltagePoints[i][1]));
            }

            Response.Write(sw.ToString());
            Response.End();
        }
    }
}