//-----------------------------------------------------------------------------
//  
//  Name: GLFWKeyMappings.h
//
//  Desc: Implements the conversion of glfw keycodes to the engine keycodes
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../Core/Backend/KeyCode.h"
#include <GLFW/glfw3.h>

inline KeyCode GLFWKeyToKeyCode(int glfwKey)
{
  switch (glfwKey) {
    
    case GLFW_KEY_A: return KeyCode::A;
    case GLFW_KEY_B: return KeyCode::B;
    case GLFW_KEY_C: return KeyCode::C;
    case GLFW_KEY_D: return KeyCode::D;
    case GLFW_KEY_E: return KeyCode::E;
    case GLFW_KEY_F: return KeyCode::F;
    case GLFW_KEY_G: return KeyCode::G;
    case GLFW_KEY_H: return KeyCode::H;
    case GLFW_KEY_I: return KeyCode::I;
    case GLFW_KEY_J: return KeyCode::J;
    case GLFW_KEY_K: return KeyCode::K;
    case GLFW_KEY_L: return KeyCode::L;
    case GLFW_KEY_M: return KeyCode::M;
    case GLFW_KEY_N: return KeyCode::N;
    case GLFW_KEY_O: return KeyCode::O;
    case GLFW_KEY_P: return KeyCode::P;
    case GLFW_KEY_Q: return KeyCode::Q;
    case GLFW_KEY_R: return KeyCode::R;
    case GLFW_KEY_S: return KeyCode::S;
    case GLFW_KEY_T: return KeyCode::T;
    case GLFW_KEY_U: return KeyCode::U;
    case GLFW_KEY_V: return KeyCode::V;
    case GLFW_KEY_W: return KeyCode::W;
    case GLFW_KEY_X: return KeyCode::X;
    case GLFW_KEY_Y: return KeyCode::Y;
    case GLFW_KEY_Z: return KeyCode::Z;

    case GLFW_KEY_SPACE: return KeyCode::SPACE;
    case GLFW_KEY_ESCAPE: return KeyCode::ESCAPE;
    case GLFW_KEY_ENTER: return KeyCode::ENTER;
    case GLFW_KEY_TAB: return KeyCode::TAB;
    case GLFW_KEY_BACKSPACE: return KeyCode::BACKSPACE;
    
    case GLFW_KEY_LEFT_SHIFT: return KeyCode::LSHIFT;
    case GLFW_KEY_RIGHT_SHIFT: return KeyCode::RSHIFT;
    case GLFW_KEY_LEFT_CONTROL: return KeyCode::LCTRL;
    case GLFW_KEY_RIGHT_CONTROL: return KeyCode::RCTRL;
    case GLFW_KEY_LEFT_ALT: return KeyCode::LALT;
    case GLFW_KEY_RIGHT_ALT: return KeyCode::RALT;

    case GLFW_KEY_0: return KeyCode::N0;
    case GLFW_KEY_1: return KeyCode::N1;
    case GLFW_KEY_2: return KeyCode::N2;
    case GLFW_KEY_3: return KeyCode::N3;
    case GLFW_KEY_4: return KeyCode::N4;
    case GLFW_KEY_5: return KeyCode::N5;
    case GLFW_KEY_6: return KeyCode::N6;
    case GLFW_KEY_7: return KeyCode::N7;
    case GLFW_KEY_8: return KeyCode::N8;
    case GLFW_KEY_9: return KeyCode::N9;

    case GLFW_KEY_F1: return KeyCode::F1;
    case GLFW_KEY_F2: return KeyCode::F2;
    case GLFW_KEY_F3: return KeyCode::F3;
    case GLFW_KEY_F4: return KeyCode::F4;
    case GLFW_KEY_F5: return KeyCode::F5;
    case GLFW_KEY_F6: return KeyCode::F6;
    case GLFW_KEY_F7: return KeyCode::F7;
    case GLFW_KEY_F8: return KeyCode::F8;
    case GLFW_KEY_F9: return KeyCode::F9;
    case GLFW_KEY_F10: return KeyCode::F10;
    case GLFW_KEY_F11: return KeyCode::F11;
    case GLFW_KEY_F12: return KeyCode::F12;

  }
}
