//-----------------------------------------------------------------------------
//  
//  Name: Window.h
//
//  Desc: Header file for the window interface which will be implemented by the
//  platform specific api (GLFW, win32, x11, SDL, etc..)
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

class Window
{
  
  public:
    
    virtual ~Window() = default;
    
    // for getting the implementation specific window handle
    virtual void* GetNativeHandle() const = 0; 
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    
    virtual bool ShouldClose() const = 0;
    
    // swaps the back and the front buffers
    virtual void SwapBuffers() = 0;

};


