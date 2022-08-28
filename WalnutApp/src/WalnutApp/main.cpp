#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include <iostream>

class ExampleLayer : public Walnut::Layer
{
public:
  ExampleLayer()
  {
    m_img = std::make_shared<Walnut::Image>("resources/1.jpg");
    std::cout << m_img->GetWidth() << std::endl;
    // m_img->Resize(100, 200);
  }
  virtual void OnUIRender() override
  {
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    // ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20),
    // ImGuiCond_FirstUseEver); ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);

    ImGui::SetNextWindowPos(ImVec2(viewport->WorkPos.x, viewport->WorkPos.y), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(viewport->WorkSize.x, viewport->WorkSize.y), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);

    ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize);
    ImGui::Button("Button");
    ImGui::Image(m_img->GetDescriptorSet(), {(float)m_img->GetWidth(), (float)m_img->GetHeight()});

    ImGui::End();
    ImGui::PopStyleVar();
    // ImGui::ShowDemoWindow();
  }

private:
  std::shared_ptr<Walnut::Image> m_img;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
  Walnut::ApplicationSpecification spec;
  spec.Name = "Walnut Example";

  Walnut::Application* app = new Walnut::Application(spec);
  app->PushLayer<ExampleLayer>();
  app->SetMenubarCallback([app]() {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Exit")) {
        app->Close();
      }
      ImGui::EndMenu();
    }
  });
  return app;
}