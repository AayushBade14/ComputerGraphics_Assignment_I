//-----------------------------------------------------------------------------
//  
//  Name: GLFWMouseMappings.h
//
//  Desc: Implements the conversion of glfw mouse-button codes to the engine mouse-button
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../Core/Backend/MouseButton.h"

inline MouseButton GLFWMouseToMouseButton(int btn)
{
  switch (btn) {
    
    case GLFW_MOUSE_BUTTON_LEFT: return MouseButton::LEFT;
    case GLFW_MOUSE_BUTTON_RIGHT: return MouseButton::RIGHT;
    case GLFW_MOUSE_BUTTON_MIDDLE: return MouseButton::MIDDLE;
    
    case GLFW_MOUSE_BUTTON_4: return MouseButton::BUTTON4;
    case GLFW_MOUSE_BUTTON_5: return MouseButton::BUTTON5;

    default: return MouseButton::NONE;
  }
}
