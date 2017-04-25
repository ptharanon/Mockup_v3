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

            return Json(new { current = output[0], torque = output[1], speed = output[2], voltage = output[3] });
        }
    }
}