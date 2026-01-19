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

std::unique_ptr<Window> WindowFactory::Create(Backend backend, const WindowProp& prop)
{
  switch(backend)
  {
    case Backend::GLFW:
      return std::make_unique<GLFWWindow>(prop);

    case Backend::SDL:
      std::cerr << "SDL Backend not implemented yet! Retry with GLFW" << std::endl;
      return nullptr;

    case Backend::UNKNOWN:
      std::cerr << "Unknown Backend! Retry with GLFW" << std::endl;
      return nullptr;

    default:
      std::cerr << "Unknown Backend! Retry with GLFW" << std::endl;
      return nullptr;
  }
}
