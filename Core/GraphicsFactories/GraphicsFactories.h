//-----------------------------------------------------------------------------
//  
//  Name: GraphicsFactories.h
//
//  Desc: Factory for creating graphics related objects
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------


#pragma once

#include "../Graphics/Shader.h"
#include "../Graphics/Buffer.h"
#include "../Graphics/VertexArray.h"
#include <memory>

class GraphicsFactories
{
  
  public:

    static std::unique_ptr<Shader> CreateShader(const std::string& p1, const std::string& p2);

    static std::unique_ptr<VertexBuffer> CreateVertexBuffer(const void* data, size_t size);

    static std::unique_ptr<VertexArray> CreateVertexArray();
};

