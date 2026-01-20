//-----------------------------------------------------------------------------
//  
//  Name: OpenGLVertexArray.h
//
//  Desc: Vertex array interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../../Core/Graphics/VertexArray.h"

class OpenGLVertexArray : public VertexArray
{

  private:

    unsigned int m_Id;

  public:

    OpenGLVertexArray();

    ~OpenGLVertexArray();

    void Bind() override;
    
    void SetAttribPointer(int loc, int nr, int stride, int offset) override;
};
