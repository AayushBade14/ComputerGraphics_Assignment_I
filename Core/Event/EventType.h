//-----------------------------------------------------------------------------
//  
//  Name: EventType.h
//
//  Desc: Declares the EventType enum class, which will be used as a part of
//  the event system
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragme once

enum class EventType
{
  // key-based event types
  KeyPressed,
  KeyReleased,
  
  // mouse based event types
  MouseMoved,
  MouseButtonPressed,
  MouseButtonReleased,

  // window based event types
  WindowResize,
  WindowClose
};
