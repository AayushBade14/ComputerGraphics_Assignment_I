//-----------------------------------------------------------------------------
//  
//  Name: VertexArray.h
//
//  Desc: Defines an interface for the VertexArray
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

class VertexArray
{

  public:

    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;
    virtual void SetAttribPointer(int loc, int nr, int stride, int offset);
};
