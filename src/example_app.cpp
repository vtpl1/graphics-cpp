#include "example_app.h"

#include "image.h"
#include "implot.h"

ExampleLayer::ExampleLayer() noexcept : x(new vtpl::Image("1.jpg")) {}

void ExampleLayer::OnUIRender()
{
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    static ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollWithMouse;
    // auto x = vtpl::Image("1.jpg");
    if (ImGui::Begin("Example: Fullscreen window", nullptr, flags))
    {
        ImGui::Button("Button");
        ImGui::Image(x->GetDescriptorSet(), ImVec2(x->GetWidth(), x->GetHeight()));
        ImGui::End();
    }
}

void ExampleLayer1::OnUIRender()
{
    ImGuiIO&     io = ImGui::GetIO();
    static float xs1[100], ys1[100];
    for (int i = 0; i < 100; ++i)
    {
        xs1[i] = i * 0.01f;
        ys1[i] = xs1[i] + 0.1f * ((float)rand() / (float)RAND_MAX);
    }
    static float xs2[50], ys2[50];
    for (int i = 0; i < 50; i++)
    {
        xs2[i] = 0.25f + 0.2f * ((float)rand() / (float)RAND_MAX);
        ys2[i] = 0.75f + 0.2f * ((float)rand() / (float)RAND_MAX);
    }
    // ImGui::Begin("Hello");
    // ImGui::Button("Button");
    // ImGui::End();

    // ImGui::ShowDemoWindow();
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    static ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollWithMouse;

    if (ImGui::Begin("Example: Fullscreen window", nullptr, flags))
    {
        ImGui::Text("M Application average %.3f ms/frame (%.1f FPS) x: %.3f, y: %.3f", 1000.0f / io.Framerate,
                    io.Framerate, viewport->Size.x, viewport->Size.y);
        if (ImPlot::BeginPlot("My Plot", ImVec2(-1, -1)))
        {
            ImPlot::PlotScatter("Data 1", xs1, ys1, 100);
            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.25f);
            ImPlot::SetNextMarkerStyle(ImPlotMarker_Square, 6, ImPlot::GetColormapColor(1), IMPLOT_AUTO,
                                       ImPlot::GetColormapColor(1));
            ImPlot::PlotScatter("Data 2", xs2, ys2, 50);
            ImPlot::PopStyleVar();
            ImPlot::EndPlot();
        }
    }
    ImGui::End();
}

vtpl::Application* vtpl::CreateApplication(int argc, char** argv)
{
    vtpl::ApplicationSpecification spec;
    spec.Name = "vtpl Example";

    vtpl::Application* app = new vtpl::Application(spec);
    app->PushLayer<ExampleLayer>();
    app->SetMenubarCallback(
        [app]()
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Exit"))
                {
                    app->Close();
                }
                ImGui::EndMenu();
            }
        });
    return app;
}