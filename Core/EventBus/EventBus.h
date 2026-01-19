//-----------------------------------------------------------------------------
//  
//  Name: EventBus.h
//
//  Desc: Declares the event bus, for carrying event messages to it's subscribers
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <vector>
#include <function>
#include <unordered_map>
#include "../Event/EventType.h"
#include "../Event/Event.h"

class EventBus
{

  private: 

    std::unordered_map<EventType, std::vector<Callback>> m_Subscribers;

  public:

    using Callback = std::function<void(const Event&)>;

    void Subscribe(EventType type, Callback cb);

    void Publish(const Event& event);
};
