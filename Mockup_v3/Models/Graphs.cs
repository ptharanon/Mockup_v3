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
    }
}