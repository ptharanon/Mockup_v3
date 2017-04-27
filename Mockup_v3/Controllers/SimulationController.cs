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

            return Json(new { signal = signal });
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

            return Json(new { signal = signal });
        }

        [HttpGet]
        public ActionResult GetPlotData(String plotname)
        {
            List<double[]> signal = new List<double[]>();
            if (plotname == "inputSpeed")
            {
                signal = graphs.InputSpeedPoints;
            }
            else if (plotname == "inputTorque")
            {
                signal = graphs.InputTorquePoints;
            }
            return Json(new { signal = signal }, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public ActionResult Simulate(String motor)
        {
            SimulationResults results = new SimulationResults();
            List<List<double[]>> output = results.startSimulation(graphs.InputSpeedPoints, graphs.InputTorquePoints, graphs.InputTorquePoints.Count);
            List<double[]> currentOutput = output[0];
            List<double[]> speedOutput = output[1];
            List<double[]> torqueOutput = output[2];
            List<double[]> voltageOutput = output[3];

            return Json(new { current = currentOutput, torque = torqueOutput, speed = speedOutput, voltage = voltageOutput }, JsonRequestBehavior.AllowGet);
        }
    }
}