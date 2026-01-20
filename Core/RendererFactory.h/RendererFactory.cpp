//-----------------------------------------------------------------------------
//  
//  Name: RendererFactory.cpp
//
//  Desc: A factory for producing the renderer
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./RendererFactory.h"
#include "../../Platform/GLFW/Renderer/OpenGLRenderer.h"
#include <iostream>
#include <cstdlib>

std::unique_ptr<Renderer> Create(const RendererContext& context)
{
  switch (context.API) {
    
    case RendererAPI::OPENGL:
      return std::make_unique<OpenGLRenderer>();

    default:
      std::cerr << "ERROR: Other RendererAPI backend not implemented! Retry with OpenGL" 
        << std::endl;

      exit(1);
  }
}
