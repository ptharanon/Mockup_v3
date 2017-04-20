using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Runtime.InteropServices;

namespace Mockup_v3.Models
{
    /*
     *  Possible issue with jqplot resolutions (i.e. output from the DLL has 2E-05 resolution, thus we might need to skip some
     *  of the outputs according to the jqplot resolution).
     */
    public class SimulationResults
    {
        //Import compiled DLL of the AC6_example model
        [DllImport(@"ac6_example_chop_dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "runSimulation")]

        //Definition for the entry point function (return type pointer - platform specific)
        public static extern IntPtr runSimulation(double[] timeVector, double[] speedInput_arr, double[] torqueInput_arr, int size);

        private int signalSize;
        private double[] speedInput;
        private double[] torqueInput;
        private double[] timeVector;

        //Function to process input data into input arrays
        public void processData(double[][] speedCoordinates, double[][] torqueCoordinates, int size)
        {
            this.signalSize = size;

            int index = 0;
            for (int i = 0; i < signalSize; i++)
            {
                timeVector[index] = speedCoordinates[i][0];
                speedInput[index] = speedCoordinates[i][1];
                index++;
            }

            index = 0;
            for (int i = 0; i < signalSize; i++)
            {
                torqueInput[index] = torqueCoordinates[i][1];
                index++;
            }
        }

        /*  Function to run the simulation
         *  Inputs: 2D double array of speed and torque, data size
         *  Outputs: One big list contains 4 different outputs (each output is represented by a list of 2D array)
         */ 
        public List<List<double[]>> startSimulation(double[][] speedCoordinates, double[][] torqueCoordinates, int size)
        {
            processData(speedCoordinates, torqueCoordinates, size);
            double[] results = new double[signalSize*6];

            List<List<double[]>> setOfOutputs = new List<List<double[]>>();
            List<double[]> stator_Current = new List<double[]>();
            List<double[]> motor_Speed = new List<double[]>();
            List<double[]> motor_Torque = new List<double[]>();
            List<double[]> DCBus_Voltage = new List<double[]>();

            try
            {
                IntPtr pointer = runSimulation(timeVector, speedInput, torqueInput, signalSize);
                Marshal.Copy(pointer, results, 0, signalSize*6);
                Marshal.FreeCoTaskMem(pointer);
                
                for(int i=0; i<signalSize; i++)
                {
                    int index_statorCurrent = i;
                    int index_motorSpeed = i + 1 * signalSize;
                    int index_motorTorque = i + 3 * signalSize;
                    int index_DCBusVoltage = i + 5 * signalSize;

                    stator_Current.Add(new double[]{ timeVector[i], results[index_statorCurrent]});
                    motor_Speed.Add(new double[] { timeVector[i], results[index_motorSpeed] });
                    motor_Torque.Add(new double[] { timeVector[i], results[index_motorTorque] });
                    DCBus_Voltage.Add(new double[] { timeVector[i], results[index_DCBusVoltage] });

                }
            }
            catch(Exception)
            {
                Console.WriteLine("Error during simulation step");
            }

            setOfOutputs.Add(stator_Current);
            setOfOutputs.Add(motor_Speed);
            setOfOutputs.Add(motor_Torque);
            setOfOutputs.Add(DCBus_Voltage);

            return setOfOutputs;
        } 
        
    }
}