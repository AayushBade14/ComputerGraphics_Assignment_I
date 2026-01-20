//-----------------------------------------------------------------------------
//  
//  Name: Problem1.h
//
//  Desc: Implements the solution of problem-1
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./Problem1.h"

#include "../../Core/WindowFactory/WindowFactory.h"
#include "../../Core/EventBusFactory/EventBusFactory.h"
#include "../../Core/InputSystemFactory/InputSystemFactory.h"

void Problem1::Run()
{
  
  std::unique_ptr<EventBus> bus = EventBusFactory::Create();

  std::unique_ptr<InputSystem> input = InputSystemFactory::Create(Backend::GLFW, *bus);

  WindowProp prop;
  prop.Width = 1280;
  prop.Height = 720;
  prop.Title = "Problem1 - B23CS1084";

  std::unique_ptr<Window> window = WindowFactory::Create(Backend::GLFW, prop, *bus, *input);

  while(!window->ShouldClose())
  {
    input->BeginFrame();
    window->PollEvents();

    window->SwapBuffers();
  }

}
