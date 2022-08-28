cmake_minimum_required(VERSION 3.15)
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_library(walnut SHARED
    src/Walnut/ImGui/ImGuiBuild.cpp
    src/Walnut/Application.cpp
    src/Walnut/Application.h
)
target_link_libraries(walnut
    PRIVATE imgui::imgui
    PRIVATE glfw
    PRIVATE glm::glm
)
