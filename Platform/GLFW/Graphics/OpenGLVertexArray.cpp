//-----------------------------------------------------------------------------
//  
//  Name: OpenGLVertexArray.cpp
//
//  Desc: Vertex array interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./OpenGLVertexArray.h"
#include <glad/glad.h>

OpenGLVertexArray::OpenGLVertexArray()
{
  glGenVertexArrays(1, &m_Id);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
  glDeleteVertexArrays(1, &m_Id);
}

void OpenGLVertexArray::Bind()
{
  glBindVertexArray(m_Id);
}

void OpenGLVertexArray::SetVertexAttribPointer(int loc, int nr, int stride, int offset)
{
  glEnableVertexAttribArray(loc);
  glVertexAttribPointer(loc, nr, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void*)offset);
}
