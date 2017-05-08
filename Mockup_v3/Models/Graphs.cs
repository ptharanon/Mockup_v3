using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Mockup_v3.Models
{
    public class Graphs
    {
        public List<List<double>> InputSpeedTrace { get; set; }
        public List<List<double>> InputTorqueTrace { get; set; }
        public List<List<double>> OutputCurrentTrace { get; set; }
        public List<List<double>> OutputTorqueTrace { get; set; }
        public List<List<double>> OutputSpeedTrace { get; set; }
        public List<List<double>> OutputVoltageTrace { get; set; }
        
        public List<List<double>> GenerateStep(double steptime, double initial, double final, double sample, double endtime)
        {
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            int j = 0;
            for (int i = 0; i <= (endtime / sample) + 1 ; i++)
            {
                if (i * sample < steptime)
                {
                    signal[0].Add(i * sample);
                    signal[1].Add(initial);
                }
                else
                {
                    signal[0].Add(i * sample);
                    signal[1].Add(final);
                }
                j++;
            }

            return signal;
        }

        public List<List<double>> GenerateRamp(double slope, double starttime, double initial, double sample, double endtime)
        {
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            for (int i = 0; i <= (endtime / sample) + 1 ; i++)
            {
                if (i * sample < starttime)
                {
                    signal[0].Add(i * sample);
                    signal[1].Add(initial);
                }
                else
                {
                    signal[0].Add(i * sample);
                    signal[1].Add((i * sample - starttime) * slope + initial);
                }
            }

            return signal;
        }

        public List<List<double>> GenerateSinusoid(double amplitude, double bias, double frequency, double phase, double sample, double endtime)
        {
            List<List<double>> signal = new List<List<double>>();
            signal.Add(new List<double>());
            signal.Add(new List<double>());
            for (int i = 0; i <= (endtime / sample) + 1 ; i++)
            {
                signal[0].Add(i * sample);
                signal[1].Add(amplitude * Math.Sin(2 * Math.PI * frequency * i * sample + phase) + bias);
            }

            return signal;
        }
    }
}