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
        [DllImport(@"Model1", CallingConvention = CallingConvention.Cdecl, EntryPoint = "runSimulation")]
        //Definition for the entry point function (return type pointer - platform specific)
        public static extern IntPtr RunModel1(double[] timeVector, double[] speedInput_arr, double[] torqueInput_arr, int size);

        //Import compiled DLL of the AC6_example model
        [DllImport(@"Model2", CallingConvention = CallingConvention.Cdecl, EntryPoint = "runSimulation")]
        //Definition for the entry point function (return type pointer - platform specific)
        public static extern IntPtr RunModel2(double[] timeVector, double[] speedInput_arr, double[] torqueInput_arr, int size);

        //Import compiled DLL of the AC6_example model
        [DllImport(@"Model3", CallingConvention = CallingConvention.Cdecl, EntryPoint = "runSimulation")]
        //Definition for the entry point function (return type pointer - platform specific)
        public static extern IntPtr RunModel3(double[] timeVector, double[] speedInput_arr, double[] torqueInput_arr, int size);

        /*  Function to run the simulation
         *  Inputs: 2D double array of speed and torque, data size
         *  Outputs: One big list contains 4 different outputs (each output is represented by a list of 2D array)
         */ 
        public List<List<List<double>>> startSimulation(string motor, List<List<double>> speedCoordinates, List<List<double>> torqueCoordinates, int size)
        {
            // Convert array of points to vectors.
            double[] speedInput = new double[size];
            double[] torqueInput = new double[size];
            double[] timeVector = new double[size];

            for (int i = 0; i < size; i++)
            {
                timeVector[i] = speedCoordinates[0][i];
                speedInput[i] = speedCoordinates[1][i];
                torqueInput[i] = torqueCoordinates[1][i];
            }
            //Calculate the simulation total steps
            double simulationTime = timeVector[size - 1] - timeVector[0];

            //Calculate the sampling time from the inptus
            double sampleTime = timeVector[1] - timeVector[0];
            
            double MODEL_SAMPLING = 1E-04;

            //Calculate new total size based on input's and model's sampling time
            int total_size = (size - 1) * (int) (sampleTime / MODEL_SAMPLING);
            int scale = total_size / size;

            double[] scaledTime = new double[total_size];

            double[] results = new double[total_size * 6];

            List<List<List<double>>> setOfOutputs = new List<List<List<double>>>();

            List<List<double>> stator_Current = new List<List<double>>();
            stator_Current.Add(new List<double>());
            stator_Current.Add(new List<double>());

            List<List<double>> motor_Speed = new List<List<double>>();
            motor_Speed.Add(new List<double>());
            motor_Speed.Add(new List<double>());

            List<List<double>> ref_Speed = new List<List<double>>();
            ref_Speed.Add(new List<double>());
            ref_Speed.Add(new List<double>());

            List<List<double>> motor_Torque = new List<List<double>>();
            motor_Torque.Add(new List<double>());
            motor_Torque.Add(new List<double>());

            List<List<double>> ref_Torque = new List<List<double>>();
            ref_Torque.Add(new List<double>());
            ref_Torque.Add(new List<double>());

            List<List<double>> DCBus_Voltage = new List<List<double>>();
            DCBus_Voltage.Add(new List<double>());
            DCBus_Voltage.Add(new List<double>());

            try
            {
                //Alllocate memories to store the simulation outputs and have a temporary pointer to point to that memory
                IntPtr pointer;
                if (motor.Contains("MA60-0630-A"))
                {
                    pointer = RunModel1(timeVector, speedInput, torqueInput, size);
                }
                else if (motor.Contains("MA80-2430-A"))
                {
                    pointer = RunModel2(timeVector, speedInput, torqueInput, size);
                }
                else
                {
                    pointer = RunModel3(timeVector, speedInput, torqueInput, size);
                }
                //Copy the temporary pointer's address to the results array's pointer
                Marshal.Copy(pointer, results, 0, total_size * 6);
                //Free the memory of the temporary pointer
                Marshal.FreeCoTaskMem(pointer);

                for (int i = 0; i < total_size; i++)
                {
                    int index_statorCurrent = i;
                    int index_motorSpeed = i + 1 * total_size;
                    int index_refSpeed = i + 2 * total_size;
                    int index_motorTorque = i + 3 * total_size;
                    int index_refTorque = i + 4 * total_size;
                    int index_DCBusVoltage = i + 5 * total_size;


                    scaledTime[i] = MODEL_SAMPLING * index_statorCurrent;

                    stator_Current[0].Add(scaledTime[i]);
                    stator_Current[1].Add(results[index_statorCurrent]);
                    motor_Speed[0].Add(scaledTime[i]);
                    motor_Speed[1].Add(results[index_motorSpeed]);
                    ref_Speed[0].Add(scaledTime[i]);
                    ref_Speed[1].Add(results[index_refSpeed]);
                    motor_Torque[0].Add(scaledTime[i]);
                    motor_Torque[1].Add(results[index_motorTorque]);
                    ref_Torque[0].Add(scaledTime[i]);
                    ref_Torque[1].Add(results[index_refTorque]);
                    DCBus_Voltage[0].Add(scaledTime[i]);
                    DCBus_Voltage[1].Add(results[index_DCBusVoltage]);
                }
            }
            catch(Exception)
            {
                System.Diagnostics.Debug.WriteLine("Error during simulation step");
            }

            setOfOutputs.Add(stator_Current);
            setOfOutputs.Add(motor_Speed);
            setOfOutputs.Add(ref_Speed);
            setOfOutputs.Add(motor_Torque);
            setOfOutputs.Add(ref_Torque);
            setOfOutputs.Add(DCBus_Voltage);

            return setOfOutputs;
        } 
        
    }


}