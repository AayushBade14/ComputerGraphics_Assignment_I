//-----------------------------------------------------------------------------
//  
//  Name: OpenGLBuffer.cpp
//
//  Desc: Buffer interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./OpenGLBuffer.h"
#include <glad/glad.h>


OpenGLVertexBuffer::OpenGLVertexBuffer()
{
  glGenBuffers(1, &m_Id);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
  glDeleteBuffers(1, &m_Id);
}

void OpenGLVertexBuffer::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void OpenGLVertexBuffer::SetData(const void* data, size_t size)
{
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
