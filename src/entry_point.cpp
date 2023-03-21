#include "application.h"
#include "example_app.h"
extern bool g_ApplicationRunning;
namespace vtpl
{

int Main(int argc, char** argv)
{
    // while (g_ApplicationRunning)
    {
        vtpl::Application* app = vtpl::CreateApplication(argc, argv);
        app->Run();
        delete app;
    }

    return 0;
}

} // namespace vtpl

#if defined(_MSC_VER)

#include <Windows.h>
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return vtpl::Main(__argc, __argv);
}
#else
int main(int argc, char** argv) { return vtpl::Main(argc, argv); }
#endif