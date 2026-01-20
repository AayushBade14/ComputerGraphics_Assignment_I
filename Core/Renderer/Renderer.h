//-----------------------------------------------------------------------------
//  
//  Name: Renderer.h
//
//  Desc: Defines an interface for the Renderer class
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

class Renderer
{

  public:
  
    virtual ~Renderer() = default;

    virtual void Init() = 0;
    virtual void Shutdown() = 0;

    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    
    virtual void SetViewport(int x, int y, int w, int h) = 0;
};
