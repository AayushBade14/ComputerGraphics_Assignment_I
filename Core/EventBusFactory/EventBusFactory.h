//-----------------------------------------------------------------------------
//  
//  Name: EventBusFactory.h
//
//  Desc: Declares the event bus factory, for producing event busses
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <memory>
#include "../EventBus/EventBus.h"

class EventBusFactory
{
  static std::unique_ptr<EventBus> Create();
};
