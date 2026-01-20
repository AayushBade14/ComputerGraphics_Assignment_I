//-----------------------------------------------------------------------------
//  
//  Name: WindowFactory.cpp
//
//  Desc: Defines the window factory class responsible for producing window
//  instances based on the set backend
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "../../Platform/GLFW/GLFWWindow.h"
#include "./WindowFactory.h"
#include <cstdlib>
#include <iostream>

std::unique_ptr<Window> WindowFactory::Create(Backend backend, const WindowProp& prop, EventBus& eventBus, InputSystem& inputSystem)
{
  switch(backend)
  {
    case Backend::GLFW:
      return std::make_unique<GLFWWindow>(prop, eventBus, inputSystem);

    case Backend::SDL:
      std::cerr << "SDL Backend not implemented yet! Retry with GLFW" << std::endl;
      exit(1);

    case Backend::UNKNOWN:
      std::cerr << "Unknown Backend! Retry with GLFW" << std::endl;
      exit(1);

    default:
      std::cerr << "Unknown Backend! Retry with GLFW" << std::endl;
      exit(1);
  }
}
