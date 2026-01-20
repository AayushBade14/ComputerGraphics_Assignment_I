//-----------------------------------------------------------------------------
//  
//  Name: GLFWWindow.h
//
//  Desc: Implements the Window interface defined in Core/Window/Window.h using
//  GLFW as it's backend.
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../Core/Window/Window.h"
#include "../../Core/Window/WindowProp.h"

struct GLFWwindow; // forward declaring the GLFWwindow struct

class GLFWWindow : public Window
{
  private:

    GLFWwindow* h_WindowHandle = nullptr;
    WindowProp m_WindowProp;
    inline static bool m_IsGLFWInit = false;
    inline static int m_WindowInstanceCount = 0;

  public:
    
    GLFWWindow(const WindowProp& prop);

    ~GLFWWindow();

    void* GetNativeHandle() const override;
    
    int GetWidth() const override;
    int GetHeight() const override;

    bool ShouldClose() const override;

    void SwapBuffers() override;
    void PollEvents() override;
};
