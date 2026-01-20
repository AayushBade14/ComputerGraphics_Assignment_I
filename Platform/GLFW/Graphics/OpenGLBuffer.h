//-----------------------------------------------------------------------------
//  
//  Name: OpenGLBuffer.h
//
//  Desc: Buffer interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../../Core/Graphics/Buffer.h"

class OpenGLVertexBuffer : public VertexBuffer
{
  
  private:

    unsigned int m_Id;

  public:

    OpenGLVertexBuffer();
    
    ~OpenGLVertexBuffer();

    void Bind() override;

    void SetData(const void* data, size_t data) override;
};
