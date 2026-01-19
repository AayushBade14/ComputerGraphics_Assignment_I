//-----------------------------------------------------------------------------
//  
//  Name: WindowFactory.h
//
//  Desc: Declares the window factory class responsible for producing window
//  instances based on the set backend
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <memory>
#include "../Backend/Backend.h"
#include "../Window/WindowProp.h"

class Window; //forward declaration of the window class

class WindowFactory
{

  public:

    static std::unique_ptr<Window> Create(Backend backend, const WindowProp& prop);
};
