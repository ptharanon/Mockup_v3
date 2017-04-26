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
        [DllImport(@"ac6_example_dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "runSimulation")]

        //Definition for the entry point function (return type pointer - platform specific)
        public static extern IntPtr runSimulation(double[] timeVector, double[] speedInput_arr, double[] torqueInput_arr, int size);


        //Function to process input data into input arrays
        public void processData(double[][] speedCoordinates, double[][] torqueCoordinates, int size)
        {
        }

        /*  Function to run the simulation
         *  Inputs: 2D double array of speed and torque, data size
         *  Outputs: One big list contains 4 different outputs (each output is represented by a list of 2D array)
         */ 
        public List<List<double[]>> startSimulation(double[][] speedCoordinates, double[][] torqueCoordinates, int size)
        {
            // Convert array of points to vectors.
            double[] speedInput = new double[size];
            double[] torqueInput = new double[size];
            double[] timeVector = new double[size];

            for (int i = 0; i < size; i++)
            {
                timeVector[i] = speedCoordinates[i][0];
                speedInput[i] = speedCoordinates[i][1];
                torqueInput[i] = torqueCoordinates[i][1];
            }
            double simulationTime = timeVector[size - 1] - timeVector[0];
            int show_steps = Math.Min((int)(4000 * simulationTime), 10000);
            double sampleTime = timeVector[1] - timeVector[0];
            double MODEL_SAMPLING = 2E-06;

            int total_size = (size - 1) * (int) (sampleTime / MODEL_SAMPLING);
            int scale = total_size / show_steps;

            double[] scaledTime = new double[show_steps];

            double[] results = new double[total_size * 6];

            List<List<double[]>> setOfOutputs = new List<List<double[]>>();
            List<double[]> stator_Current = new List<double[]>();
            List<double[]> motor_Speed = new List<double[]>();
            List<double[]> motor_Torque = new List<double[]>();
            List<double[]> DCBus_Voltage = new List<double[]>();

            try
            {
                IntPtr pointer = runSimulation(timeVector, speedInput, torqueInput, size);
                Marshal.Copy(pointer, results, 0, total_size * 6);
                Marshal.FreeCoTaskMem(pointer);
                
                for(int i=0; i< show_steps; i++)
                {
                    /*
                    int index_statorCurrent = i;
                    int index_motorSpeed = i + 1 * size;
                    int index_motorTorque = i + 3 * size;
                    int index_DCBusVoltage = i + 5 * size;
                    */

                    int index_statorCurrent = i * scale;
                    int index_motorSpeed = i*scale + 1 * total_size;
                    int index_motorTorque = i*scale + 3 * total_size;
                    int index_DCBusVoltage = i*scale + 5 * total_size;


                    scaledTime[i] = 0.00002 * index_statorCurrent;

                    stator_Current.Add(new double[] { scaledTime[i], results[index_statorCurrent] });
                    motor_Speed.Add(new double[] { scaledTime[i], results[index_motorSpeed] });
                    motor_Torque.Add(new double[] { scaledTime[i], results[index_motorTorque] });
                    DCBus_Voltage.Add(new double[] { scaledTime[i], results[index_DCBusVoltage] });

                    /*
                    stator_Current.Add(new double[]{ timeVector[i], results[index_statorCurrent]});
                    motor_Speed.Add(new double[] { timeVector[i], results[index_motorSpeed] });
                    motor_Torque.Add(new double[] { timeVector[i], results[index_motorTorque] });
                    DCBus_Voltage.Add(new double[] { timeVector[i], results[index_DCBusVoltage] });
                    */

                    //System.Diagnostics.Debug.WriteLine(stator_Current[i]+",");
                }
            }
            catch(Exception)
            {
                System.Diagnostics.Debug.WriteLine("Error during simulation step");
            }

            setOfOutputs.Add(stator_Current);
            setOfOutputs.Add(motor_Speed);
            setOfOutputs.Add(motor_Torque);
            setOfOutputs.Add(DCBus_Voltage);

            return setOfOutputs;
        } 
        
    }


}