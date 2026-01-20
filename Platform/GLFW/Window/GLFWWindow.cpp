//-----------------------------------------------------------------------------
//  
//  Name: GLFWWindow.cpp
//
//  Desc: Implements the Window interface defined in Core/Window/Window.h using
//  GLFW as it's backend.
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include <GLFW/glfw3.h>
#include "./GLFWWindow.h"
#include "../Mappings/GLFWKeyMappings.h"
#include "../Mappings/GLFWMouseMappings.h"
#include <iostream>
#include <cstdlib>

GLFWWindow::GLFWWindow(const WindowProp& prop, EventBus& eventBus, InputSystem& inpytSystem) : 
m_WindowProp(prop),
r_EventBus(eventBus),
r_InputSystem(inpytSystem)
{
  if(!m_IsGLFWInit)
  {
    if(glfwInit() < 0)
    {
      std::cerr << "ERROR: GLFW::Init()" << std::endl;
      exit(1);
    }
  }

  m_WindowInstanceCount++;

  //TO-DO: Make this graphics-api agnostic
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  h_WindowHandle = glfwCreateWindow(
    m_WindowProp.Width,
    m_WindowProp.Height,
    m_WindowProp.Title.c_str(),
    nullptr,
    nullptr
  );

  if(!h_WindowHandle)
  {
    std::cerr << "ERROR: GLFW_WINDOW::Create()" << std::endl;
    exit(1);
  }
  
  glfwSetWindowUserPointer(h_WindowHandle, this);

  RegisterCallbacks();

  std::cout << "Successfully created a GLFW_WINDOW instance | Total Window instances: " 
  << m_WindowInstanceCount << std::endl;

}

GLFWWindow::~GLFWWindow()
{
  glfwDestroyWindow(h_WindowHandle);
  
  m_WindowInstanceCount--;

  if(m_IsGLFWInit && m_WindowInstanceCount == 0)
  {
    glfwTerminate();
  }

}

void* GLFWWindow::GetNativeHandle() const
{
  return static_cast<void*>(h_WindowHandle);
}

int GLFWWindow::GetWidth() const
{
  return m_WindowProp.Width;
}

int GLFWWindow::GetHeight() const
{
  return m_WindowProp.Height;
}

bool GLFWWindow::ShouldClose() const
{
  return glfwWindowShouldClose(h_WindowHandle);
}

void GLFWWindow::SwapBuffers()
{
  glfwSwapBuffers(h_WindowHandle);
}

void GLFWWindow::PollEvents()
{
  glfwPollEvents();
}

void GLFWWindow::RegisterCallbacks()
{
  glfwSetKeyCallback(h_WindowHandle,
    [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
      GLFWWindow* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
      
      if(!self) return;
      
      KeyCode translated = GLFWKeyToKeyCode(key);
      
      if(action == GLFW_PRESS || action == GLFW_REPEAT)
      {
        self->r_InputSystem.OnKeyPressed(translated, action == GLFW_REPEAT);
      }
      else if(action == GLFW_RELEASE)
      {
        self->r_InputSystem.OnKeyReleased(translated);
      }
    }
  );

  glfwSetFramebufferSizeCallback(h_WindowHandle,
    [](GLFWwindow* window, int width, int height)
    {
      GLFWWindow* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));

      if(!self) return;

      self->r_EventBus.Publish(WindowResizeEvent(width, height));
    }
  );

  glfwSetWindowCloseCallback(h_WindowHandle,
    [](GLFWwindow* window)
    {
      GLFWWindow* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));

      if(!self) return;

      self->r_EventBus.Publish(WindowCloseEvent());
    }
  );

  glfwSetMouseButtonCallback(h_WindowHandle
    [](GLFWwindow* window, int btn, int action, int mods)
    {
      GLFWWindow* self = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));

      if(!self) return;
      
      MouseButton translated = GLFWMouseToMouseButton(btn);

      if(action == GLFW_PRESS || GLFW_REPEAT)
      {
        self->r_InputSystem.OnMouseButtonPressed(translated, action == GLFW_REPEAT);
      }
      else if(action == GLFW_RELEASE)
      {
        self->r_InputSystem.OnMouseButtonReleased(btn);
      }
    }
  );
}
