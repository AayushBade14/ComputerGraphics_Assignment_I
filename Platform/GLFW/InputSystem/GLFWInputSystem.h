//-----------------------------------------------------------------------------
//  
//  Name: GLFWInputSystem.h
//
//  Desc: Implements the InputSystem interface with GLFW backend 
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../../Core/InputSystem/InputSystem.h"
#include <unordered_map>

class GLFWInputSystem : public InputSystem
{

  private:

    std::unordered_map<KeyCode, bool> m_KeyStates;
    std::unordered_map<MouseButton, bool> m_MouseButtonStates;

    float m_MouseDX;
    float m_MouseDY;
    
    float m_ScrollX;
    float m_ScrollY;

    EventBus& r_EventBus;

  public:

    void BeginFrame() override;
    void PollEvents() override;

    bool IsKeyDown(KeyCode key) const override;
    bool IsMouseButtonDown(MouseButton btn) const override;
    std::pair<float, float> GetMousePosition() const override;

    void OnKeyPressed(KeyCode key, bool repeat) override;
    void OnKeyReleased(KeyCode key) override;

    void OnMouseButtonPressed(MouseButton btn, bool repeat) override;
    void OnMouseButtonReleased(MouseButton btn) override;

};
