//-----------------------------------------------------------------------------
//  
//  Name: InputSystemFactory.h
//
//  Desc: Declares the factory for creating input systems
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <memory>
#include "../InputSystem/InputSystem.h"
#include "../EventBus/EventBus.h"
#include "../Backend/Backend.h"

class InputSystemFactory
{
  
  public:

    static std::unique_ptr<InputSystem> Create(Backend backend, EventBus& eventBus);
};
