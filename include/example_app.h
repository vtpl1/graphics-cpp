// *****************************************************
//    Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#pragma once
#ifndef example_app_h
#define example_app_h
#include "application.h"
#include "graphics_cpp_export.h"
#include "image.h"
#include <memory>

class GRAPHICS_CPP_EXPORT ExampleLayer : public vtpl::Layer
{
  public:
    ExampleLayer() noexcept;
    virtual void                 OnUIRender() override;
    std::unique_ptr<vtpl::Image> x;
};

class GRAPHICS_CPP_EXPORT ExampleLayer1 : public vtpl::Layer
{
  public:
    virtual void OnUIRender() override;
};
#endif // example_app_h
