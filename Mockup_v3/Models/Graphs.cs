using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Mockup_v3.Models
{
    public class Graphs
    {
        public List<double[]> InputSpeedPoints { get; set; }
        public List<double[]> InputTorquePoints { get; set; }
        public List<double[]> OutputCurrentPoints { get; set; }
        public List<double[]> OutputTorquePoints { get; set; }
        public List<double[]> OutputSpeedPoints { get; set; }
        public List<double[]> OutputVoltagePoints { get; set; }
    }
}