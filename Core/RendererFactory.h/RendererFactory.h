//-----------------------------------------------------------------------------
//  
//  Name: RendererFactory.h
//
//  Desc: A factory for producing the renderer
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../Renderer/Renderer.h"
#include "../Renderer/RendererContext.h"
#include <memory>

class RendererFactory
{

  public:

    static std::unique_ptr<Renderer> Create(const RendererContext& context);
};
