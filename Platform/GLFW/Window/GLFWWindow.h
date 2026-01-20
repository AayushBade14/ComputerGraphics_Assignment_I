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

#include "../../../Core/Window/Window.h"
#include "../../../Core/Window/WindowProp.h"
#include "../../../Core/InputSystem/InputSystem.h"
#include "../../../Core/EventBus/EventBus.h"

struct GLFWwindow; // forward declaring the GLFWwindow struct

class GLFWWindow : public Window
{
  private:

    GLFWwindow* h_WindowHandle = nullptr;
    WindowProp m_WindowProp;
    
    EventBus& r_EventBus;
    InputSystem& r_InputSystem;

    inline static bool m_IsGLFWInit = false;
    inline static int m_WindowInstanceCount = 0;
    
    void RegisterCallbacks();
    
    void OnWindowClose();

  public:
    
    GLFWWindow(const WindowProp& prop, EventBus& eventBus, InputSystem& inputSystem);

    ~GLFWWindow();

    void* GetNativeHandle() const override;
    
    int GetWidth() const override;
    int GetHeight() const override;

    bool ShouldClose() const override;

    void SwapBuffers() override;
    void PollEvents() override;
};
