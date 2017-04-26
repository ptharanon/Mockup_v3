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
        // GET: Simulation
        public ActionResult Index()
        {
            return View();
        }


        [HttpPost]
        public ActionResult Simulate(String motor, String inputSpeed, String inputTorque, int size)
        {
            JavaScriptSerializer js = new JavaScriptSerializer();
            double[][] speedCoordinates = js.Deserialize<double[][]>(inputSpeed);
            double[][] torqueCoordinates = js.Deserialize<double[][]>(inputTorque);

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