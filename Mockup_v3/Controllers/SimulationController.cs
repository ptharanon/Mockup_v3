using Mockup_v3.Models;
using System;
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
            //List<List<double[]>> output = results.startSimulation(speedCoordinates, torqueCoordinates, size);

            // Perform some manipulation on output here.

            //return Json(new { output = output }, JsonRequestBehavior.AllowGet
            return Json(new { motor = motor, inputSpeed = inputSpeed, inputTorque = inputTorque, size = size });
        }
    }
}