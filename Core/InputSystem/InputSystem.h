//-----------------------------------------------------------------------------
//  
//  Name: InputSystem.h
//
//  Desc: Declares an interface for the input system which will be implemented by the 
//  platform specific apis
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../Backend/KeyCode.h"
#include "../Backend/MouseButton.h"
#include <utility>

class InputSystem
{

  public:

    virtual ~InputSystem() = default;

    virtual void BeginFrame() = 0;
    
    // query state
    virtual bool IsKeyDown(KeyCode key) const = 0;
    virtual bool IsMouseButtonDown(MouseButton btn) const = 0;
    //virtual std::pair<float, float> GetMousePosition() const = 0;

    virtual void OnKeyPressed(KeyCode key, bool repeat) = 0;
    virtual void OnKeyReleased(KeyCode key) = 0;

    virtual void OnMouseButtonPressed(MouseButton btn, bool repeat) = 0;
    virtual void OnMouseButtonReleased(MouseButton btn) = 0;
};
