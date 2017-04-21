using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

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
        public ActionResult Simulate(String test)
        {
            return Json(new { testresult = test }, JsonRequestBehavior.AllowGet);
        }
    }
}