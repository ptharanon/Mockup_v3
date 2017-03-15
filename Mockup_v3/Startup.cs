using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Mockup_v3.Startup))]
namespace Mockup_v3
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
