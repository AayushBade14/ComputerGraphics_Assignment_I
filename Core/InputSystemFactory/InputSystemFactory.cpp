//-----------------------------------------------------------------------------
//  
//  Name: InputSystemFactory.cpp
//
//  Desc: Defines the factory for creating input systems
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "../../Platform/GLFW/InputSystem/GLFWInputSystem.h"
#include "./InputSystemFactory.h"
#include <cstdlib>
#include <iostream>

std::unique_ptr<InputSystem> InputSystemFactory::Create(Backend backend, EventBus& eventBus)
{
  switch(backend)
  {
    case Backend::GLFW:
      return std::make_unique(GLFWInputSystem(eventBus));

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
