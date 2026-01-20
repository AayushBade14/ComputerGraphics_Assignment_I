//-----------------------------------------------------------------------------
//  
//  Name: Application.h
//
//  Desc: Header for the application class - the main application instance
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../Core/WindowFactory/WindowFactory.h"
#include "../Core/EventBus/EventBus.h"
#include "../Core/InputSystem/InputSystem.h"
#include "../AssignmentProblems/AssignmentProblems.h"
#include <memory>

class Application
{
  
  private:
    
    std::unique_ptr<Window> p_Window;
    std::unique_ptr<EventBus> p_EventBus;
    std::unique_ptr<InputSystem> p_InputSystem;
    
    std::vector<std::unique_ptr<AssignmentProblems>> m_AssignmentProblems;
    AssignmentProblems* p_CurrentProblem = nullptr;
    
    void OnKeyPress();
    
    void OnWindowClose();

  public:
    
    Application(Backend backend, const WindowProp& prop);

    ~Application() = default;
    
    void PushAssignmentProblem(std::unique_ptr<AssignmentProblems> problem);

    void Run();
};
