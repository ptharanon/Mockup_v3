using Mockup_v3.Models;
using System;
using System.Collections.Generic;
using System.Web.Mvc;
using System.Web.Script.Serialization;

namespace Mockup_v3.Controllers
{
    [Authorize]
    public class SimulationController : Controller
    {
        Graphs graphs = new Graphs();

        // GET: Simulation
        public ActionResult Index()
        {
            return View();
        }

        public List<double[]> GenerateStep(double steptime, double initial, double final, double sample, double endtime)
        {
            List<double[]> signal = new List<double[]>();
            for (int i = 0; i < endtime / sample; i++)
            {
                if (i * sample < steptime)
                {
                    signal.Add(new double[] { i * sample, initial });
                }
                else
                {
                    signal.Add(new double[] { i * sample, final });
                }
            }

            return signal;
        }

        public List<double[]> GenerateRamp(double slope, double starttime, double initial, double sample, double endtime)
        {
            List<double[]> signal = new List<double[]>();
            for (int i = 0; i < endtime / sample; i++)
            {
                if (i * sample < starttime)
                {
                    signal.Add(new double[] { i * sample, initial });
                }
                else
                {
                    signal.Add(new double[] { i * sample, (i * sample - starttime) * slope + initial });
                }
            }

            return signal;
        }

        public List<double[]> GenerateSinusoid(double amplitude, double bias, double frequency, double phase, double sample, double endtime)
        {
            List<double[]> signal = new List<double[]>();
            for (int i = 0; i < endtime / sample; i++)
            {
                signal.Add(new double[] { i * sample, amplitude * Math.Sin(2 * Math.PI * frequency * i * sample + phase) + bias });
            }

            return signal;
        }

        [HttpPost]
        public ActionResult UpdateGraph(String plot, String type, double param1, double param2, double param3, double param4)
        {
            double sample = 2 * Math.Pow(10, -5);
            double endtime = 1;
            List<double[]> signal = new List<double[]>();
            if (type == "Step")
            {
                signal = GenerateStep(param1, param2, param3, sample, endtime);
            }
            else if (type == "Ramp")
            {
                signal = GenerateRamp(param1, param2, param3, sample, endtime);
            }
            else if (type == "Sinusoid")
            {
                signal = GenerateSinusoid(param1, param2, param3, param4, sample, endtime);
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

        public List<double[]> GetSpeedPlot()
        {
            return graphs.InputSpeedPoints;
        }

        public List<double[]> GetTorquePlot()
        {
            return graphs.InputTorquePoints;
        }

        [HttpPost]
        public ActionResult Simulate(String motor, String inputSpeed, String inputTorque, int size)
        {
            JavaScriptSerializer js = new JavaScriptSerializer();
            List<double[]> speedCoordinates = js.Deserialize<List<double[]>>(inputSpeed);
            List<double[]> torqueCoordinates = js.Deserialize<List<double[]>>(inputTorque);

            SimulationResults results = new SimulationResults();
            List<List<double[]>> output = results.startSimulation(speedCoordinates, torqueCoordinates, size);
            List<double[]> currentOuput = output[0];
            List<double[]> speedOuput = output[1];
            List<double[]> torqueOuput = output[2];
            List<double[]> voltageOuput = output[3];

            return Json(new { current = currentOuput, torque = torqueOuput, speed = speedOuput, voltage = voltageOuput }, JsonRequestBehavior.AllowGet);
        }
    }
}