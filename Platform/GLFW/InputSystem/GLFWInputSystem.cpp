//-----------------------------------------------------------------------------
//  
//  Name: GLFWInputSystem.cpp
//
//  Desc: Implements the InputSystem interface with GLFW backend 
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./GLFWInputSystem.h"
#include "../Window/GLFWWindow.h"

GLFWInputSystem::GLFWInputSystem(EventBus& bus) r_EventBus(bus)
{
  if(!GLFWWindow::m_IsGLFWInit)
  {
    if(glfwInit() < 0)
    {
      std::cerr << "ERROR: GLFW::Init()" << std::endl;
      exit(1);
    }
  }

}

GLFWInputSystem::~GLFWInputSystem()
{
  if(GLFWWindow::m_IsGLFWInit && GLFWWindow::m_WindowInstanceCount == 0)
  {
    glfwTerminate();
  }
}

void GLFWInputSystem::BeginFrame()
{
  m_MouseDX = 0.0f;
  m_MouseDY = 0.0f;
  m_ScrollX = 0.0f;
  m_ScrollY = 0.0f;
}

void GLFWInputSystem::PollEvents()
{
  glfwPollEvents();
}

bool GLFWInputSystem::IsKeyDown(KeyCode key) const
{

}
