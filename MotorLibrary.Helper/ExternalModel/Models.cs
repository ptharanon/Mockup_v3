using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace MotorLibrary.Helper.ExternalModel
{
    /// <summary>  
    /// This class is being serialized to XML.  
    /// </summary>  
    [Serializable]
    [XmlRoot("Models"), XmlType("Models")]
    public class Models
    {
        public string ModelName { get; set; }
        
        public double Resistance { get; set; }
        public double D_Axis_Inductance { get; set; }
        public double Q_Axis_Inductance { get; set; }
        public double FluxConstant { get; set; }
        public double Inertia { get; set; }
        public double Friction { get; set; }
        public int PolePair { get; set; }
        public double InitialSpeed { get; set; }
        public double InitialAngle { get; set; }
        public double InitialCurrentA { get; set; }
        public double InitialCurrentB { get; set; }
        
    }
}
