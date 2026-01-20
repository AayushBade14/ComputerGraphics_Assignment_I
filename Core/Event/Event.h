//-----------------------------------------------------------------------------
//  
//  Name: Event.h
//
//  Desc: Declares a struct for the Event from which other events can inherit
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "./EventType.h"
#include "../Backend/KeyCode.h"
#include "../Backend/MouseButton.h"

struct Event
{
  EventType type;
};

struct KeyPressedEvent : Event
{
  KeyCode key;
  bool isHeld;

  KeyPressedEvent(KeyCode k, bool r)
  {
    type = EventType::KeyPressed;
    key = k;
    isHeld = r;
  }
};

struct KeyReleasedEvent : Event
{
  KeyCode key;

  KeyReleasedEvent(KeyCode k)
  {
    type = EventType::KeyReleased;
    key = k;
  }
};

struct MouseMovedEvent : Event
{
  float x;
  float y;
  float dx;
  float dy;

  MouseMovedEvent(float x, float y, float dx, float dy)
  {
    type = EventType::MouseMoved;
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
  }
};

struct MouseButtonPressedEvent : Event
{
  MouseButton button;
  bool isHeld;

  MouseButtonPressedEvent(MouseButton btn, bool r)
  {
    type = EventType::MouseButtonPressed;
    button = btn;
    isHeld = r;
  }
};

struct MouseButtonReleasedEvent : Event
{
  MouseButton button;

  MouseButtonReleasedEvent(MouseButton btn)
  {
    type = EventType::MouseButtonReleased;
    button = btn;
  }
};

struct WindowResizeEvent : Event
{
  int width;
  int height;

  WindowResizeEvent(int w, int h)
  {
    type = EventType::WindowResize;
    width = w;
    height = h;
  }
};

struct WindowCloseEvent : Event
{
  WindowCloseEvent()
  {
    type = EventType::WindowClose;
  }
};
