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

GLFWInputSystem::GLFWInputSystem(EventBus& bus) : r_EventBus(bus)
{}

GLFWInputSystem::~GLFWInputSystem() {}

void GLFWInputSystem::BeginFrame()
{
  m_MouseDX = 0.0f;
  m_MouseDY = 0.0f;
  m_ScrollX = 0.0f;
  m_ScrollY = 0.0f;
}

bool GLFWInputSystem::IsKeyDown(KeyCode key) const
{
  auto it = m_KeyStates.find(key);
  return (it != m_KeyStates.end()) ? it->second : false;
}

bool GLFWInputSystem::IsMouseButtonDown(MouseButton btn) const
{
  auto it = m_MouseButtonStates.find(btn);
  return (it != m_MouseButtonStates.end()) ? it->second : false;
}

void GLFWInputSystem::OnKeyPressed(KeyCode key, bool repeat)
{
  m_KeyStates[key] = true;

  r_EventBus.Publish(KeyPressedEvent{key, repeat});
}

void GLFWInputSystem::OnKeyReleased(KeyCode key)
{
  m_KeyStates[key] = false;

  r_EventBus.Publish(KeyReleasedEvent{key});
}

void GLFWInputSystem::OnMouseButtonPressed(MouseButton btn, bool repeat)
{
  m_MouseButtonStates[btn] = true;

  r_EventBus.Publish(MouseButtonPressedEvent{btn, repeat});
} 

void GLFWInputSystem::OnMouseButtonReleased(MouseButton btn)
{
  m_MouseButtonStates[btn] = false;

  r_EventBus.Publish(MouseButtonReleasedEvent{btn});
}
