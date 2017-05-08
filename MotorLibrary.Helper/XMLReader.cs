using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;  
using System.Data;
using MotorLibrary.Helper.ExternalModel;  

namespace MotorLibrary.Helper
{
    public class XMLReader
    {
        /// <summary>  
        /// Return list of products from XML.  
        /// </summary>  
        /// <returns>List of products</returns>  
        public List<Models> RetrunListOfProducts()
        {
            string xmlData = HttpContext.Current.Server.MapPath("~/App_Data/MotorLibrary.xml");//Path of the xml script  
            DataSet ds = new DataSet();//Using dataset to read xml file  
            ds.ReadXml(xmlData);
            var models = new List<Models>();
            models = (from rows in ds.Tables[0].AsEnumerable()
                        select new Models
                        {
                            ModelName = rows[0].ToString(),
                            Resistance = Convert.ToDouble(rows[1].ToString()),
                            D_Axis_Inductance = Convert.ToDouble(rows[2].ToString()),
                            Q_Axis_Inductance = Convert.ToDouble(rows[3].ToString()),
                            FluxConstant = Convert.ToDouble(rows[4].ToString()),
                            Inertia = Convert.ToDouble(rows[5].ToString()),
                            Friction = Convert.ToDouble(rows[6].ToString()),
                            PolePair = Convert.ToInt16(rows[7].ToString()),
                            InitialSpeed = Convert.ToDouble(rows[8].ToString()),
                            InitialAngle = Convert.ToDouble(rows[9].ToString()),
                            InitialCurrentA = Convert.ToDouble(rows[10].ToString()),
                            InitialCurrentB = Convert.ToDouble(rows[11].ToString()),
                            
                            /*
                            ModelName = Convert.ToInt32(rows[0].ToString()), //Convert row to int  
                            ProductName = rows[1].ToString(),
                            ProductCost = rows[2].ToString(),
                            */
                        }).ToList();
            return models;
        }
    }

}
