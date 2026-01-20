//-----------------------------------------------------------------------------
//  
//  Name: RendererContext.h
//
//  Desc: Defines a struct for holding the rendering context -> the API enum value
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../Backend/RendererAPI.h"

struct RendererContext
{
  RendererAPI API = RendererAPI::NONE;
};
