﻿using System.Web;
using System.Web.Optimization;

namespace Mockup_v3
{
    public class BundleConfig
    {
        // For more information on bundling, visit http://go.microsoft.com/fwlink/?LinkId=301862
        public static void RegisterBundles(BundleCollection bundles)
        {
            bundles.Add(new ScriptBundle("~/bundles/jquery").Include(
                         "~/Scripts/jquery.min.js"));

            bundles.Add(new ScriptBundle("~/bundles/jqueryval").Include(
                        "~/Scripts/jquery.validate*"));

            bundles.Add(new ScriptBundle("~/bundles/custom").Include(
                "~/Scripts/jquery.easing.{version}.js",
                "~/Scripts/jquery.easing.min.js",
                "~/Scripts/jquery.scrollTo.js",
                "~/Scripts/wow.min.js",
                "~/Scripts/custom.js",
                "~/Scripts/plotly.min.js"));

            // Use the development version of Modernizr to develop with and learn from. Then, when you're
            // ready for production, use the build tool at http://modernizr.com to pick only the tests you need.
            bundles.Add(new ScriptBundle("~/bundles/modernizr").Include(
                        "~/Scripts/modernizr-*"));

            bundles.Add(new ScriptBundle("~/bundles/bootstrap").Include(
                      "~/Scripts/bootstrap.js",
                      "~/Scripts/respond.js"));

            bundles.Add(new Bundle("~/Content/css").Include(
                      "~/Content/googlefont.css",
                      "~/Content/bootstrap.css",
                      "~/Content/bootstrap.min.css",
                      "~/Content/About.css",
                      "~/Content/animate.css",
                      "~/Content/style.css",
                      "~/Content/simulation.css"));

            bundles.Add(new StyleBundle("~/Content/Color").Include(
                "~/Content/default.css"));

            bundles.Add(new StyleBundle("~/Content/Font").Include(
                "~/Content/font-awesome.css"));
        }
    }
}
