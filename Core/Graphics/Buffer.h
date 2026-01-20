//-----------------------------------------------------------------------------
//  
//  Name: Buffer.h
//
//  Desc: Defines an interface for buffer implementation
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <cstdlib>

class VertexBuffer
{
  
  public:

    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;
    virtual void SetData(const void* data, size_t size) = 0; 
};
