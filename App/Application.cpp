//-----------------------------------------------------------------------------
//  
//  Name: Application.cpp
//
//  Desc: Defination of the application class 
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./Application.h"
#include <cstdlib>
#include <iostream>

Application::Application(Backend backend, const WindowProp& prop)
{
  p_EventBus = EventBusFactory::Create();

  p_InputSystem = InputSystemFactory::Create(backend, *p_EventBus);

  p_Window = WindowFactory::Create(backend, prop, *p_EventBus, *p_InputSystem);

  if(!p_EventBus || !p_InputSystem || !p_Window)
  {
    std::cerr << "ERROR: Initializing the application" << std::endl;
    exit(1);
  }

  //subscribe to the keypressed events
  p_EventBus->Subscribe(EventType::KeyPressed,
    [this](const Event& e)
    {
      const auto& keyEvent = static_cast<const KeyPressedEvent&>(e);
      OnKeyPress(keyEvent);
    }
  );
}

void Application::PushAssignmentProblem(std::unique_ptr<AssignmentProblems> problem)
{
  p_CurrentProblem = problem.get();
  m_AssignmentProblems.push_back(std::move(problem));
}

void Application::OnKeyPress(const KeyPressedEvent& e)
{
  if(e.isHeld) return;

  switch (e.key) {
    case KeyCode::ESCAPE:
      p_EventBus->Publish(WindowCloseEvent());
      break;

    case KeyCode::F1:
      if(!m_AssignmentProblems.empty())
        p_CurrentProblem = m_AssignmentProblems[0].get();
      std::cout << "Switching to problem-1" << std::endl;
      break;

    case KeyCode::F2:
      if(m_AssignmentProblems.size() == 2)
        p_CurrentProblem = m_AssignmentProblems[1].get();
      std::cout << "Switching to problem-2" << std::endl;
      break;
  }
}

void Application::Run()
{
  if(!p_CurrentProblem)
  {
    std::cerr << "ERROR: Current problem is not set!" << std::endl;
    exit(1);
  }

  while(!p_Window->ShouldClose())
  {
    p_InputSystem->BeginFrame();
    p_Window->PollEvents();
    
    p_CurrentProblem->Run();

    p_Window->SwapBuffers();
  }
}
