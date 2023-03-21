// *****************************************************
//    Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#pragma once
#ifndef example_app_h
#define example_app_h
#include "graphics_cpp_export.h"
#include "application.h"
class GRAPHICS_CPP_EXPORT ExampleLayer : public vtpl::Layer
{
  public:
    virtual void OnUIRender() override;
};

#endif // example_app_h
