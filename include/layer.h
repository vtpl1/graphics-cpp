// *****************************************************
//    Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#pragma once
#ifndef layer_h
#define layer_h
namespace vtpl
{
class Layer
{
  public:
    virtual ~Layer() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}

    virtual void OnUpdate(float ts) {}
    virtual void OnUIRender() {}
};
} // namespace vtpl

#endif // layer_h
