//-----------------------------------------------------------------------------
//  
//  Name: OpenGLRenderer.h
//
//  Desc: Implements the renderer interface using OpenGL as it's backend
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../../Core/Renderer/Renderer.h"

class OpenGLRenderer : public Renderer
{
  
  public:

    void Init() override;
    void Shutdown() override;

    void BeginFrame() override;
    void EndFrame() override;

    void SetViewport(int x, int y, int w, int h) override;
};

