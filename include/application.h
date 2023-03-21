// *****************************************************
//  Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#pragma once
#ifndef application_h
#define application_h
#include "graphics_cpp_export.h"
void GRAPHICS_CPP_EXPORT test();
#include "imgui.h"
#include "layer.h"
#include "vulkan/vulkan.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>

void check_vk_result(VkResult err);

struct GLFWwindow;

namespace vtpl
{
struct ApplicationSpecification
{
    std::string Name = "Vtpl App";
    uint32_t    Width = 1600;
    uint32_t    Height = 900;
};

class Application
{
  private:
    /* data */
  public:
    Application(const ApplicationSpecification& applicationSpecification = ApplicationSpecification());
    ~Application();
    static Application& Get();

    void Run();
    void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

    template <typename T> void PushLayer()
    {
        static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
        m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
    }

    void PushLayer(const std::shared_ptr<Layer>& layer)
    {
        m_LayerStack.emplace_back(layer);
        layer->OnAttach();
    }

    void Close();

    float       GetTime();
    GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

    static VkInstance       GetInstance();
    static VkPhysicalDevice GetPhysicalDevice();
    static VkDevice         GetDevice();

    static VkCommandBuffer GetCommandBuffer(bool begin);
    static void            FlushCommandBuffer(VkCommandBuffer commandBuffer);

    static void SubmitResourceFree(std::function<void()>&& func);

  private:
    void Init();
    void Shutdown();

  private:
    ApplicationSpecification m_applicationSpecification;
    GLFWwindow*              m_WindowHandle = nullptr;
    bool                     m_Running = false;

    float m_TimeStep = 0.0f;
    float m_FrameTime = 0.0f;
    float m_LastFrameTime = 0.0f;

    std::vector<std::shared_ptr<Layer>> m_LayerStack;
    std::function<void()>               m_MenubarCallback;
};

// Implemented by CLIENT
Application* CreateApplication(int argc, char** argv);

} // namespace vtpl
#endif // application_h
