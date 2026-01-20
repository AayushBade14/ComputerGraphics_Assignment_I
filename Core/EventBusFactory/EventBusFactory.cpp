//-----------------------------------------------------------------------------
//  
//  Name: EventBusFactory.cpp
//
//  Desc: Defines the event bus factory, for producing event busses
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./EventBusFactory.h"

std::unique_ptr<EventBus> EventBusFactory::Create()
{
  return std::make_unique<EventBus>();
}
