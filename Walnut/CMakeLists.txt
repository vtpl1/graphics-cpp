cmake_minimum_required(VERSION 3.15)
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")

add_library(walnut STATIC
    src/Walnut/ImGui/ImGuiBuild.cpp
    src/Walnut/Application.cpp
    src/Walnut/Image.cpp
    src/Walnut/Random.cpp
    src/Walnut/Input/Input.cpp
    src/Walnut/Application.h
)
target_link_libraries(walnut
    PUBLIC imgui::imgui
    PRIVATE glfw
    PRIVATE glm::glm
)
target_compile_definitions(walnut
    PUBLIC WL_PLATFORM_WINDOWS
)
target_compile_features(walnut
    PUBLIC cxx_std_17
)
target_include_directories(walnut
    PUBLIC src
    PRIVATE ${STB_INCLUDE_DIRS}
)