//-----------------------------------------------------------------------------
//  
//  Name: EventBus.cpp
//
//  Desc: Defines the event bus, for carrying event messages to it's subscribers
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./EventBus.h"

void EventBus::Subscribe(EventType type, Callback cb)
{
  m_Subscribers[type].push_back(std::move(cb));
}

void EventBus::Publish(const Event& event)
{
  auto it = m_Subscribers.find(event.type);
  if(it == m_Subscribers.end())
  {
    return;
  }

  for(auto& cb : it->second)
  {
    cb(event);
  }

}
