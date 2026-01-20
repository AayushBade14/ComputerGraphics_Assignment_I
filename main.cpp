/*
██████  ██████  ██████   ██████ ███████  ██  ██████   █████  ██   ██ 
██   ██      ██      ██ ██      ██      ███ ██  ████ ██   ██ ██   ██ 
██████   █████   █████  ██      ███████  ██ ██ ██ ██  █████  ███████ 
██   ██ ██           ██ ██           ██  ██ ████  ██ ██   ██      ██ 
██████  ███████ ██████   ██████ ███████  ██  ██████   █████       ██ 
*/

#include "./App/Application.h"
#include "./AssignmentProblems/Problem1/Problem1.h"

int main(void)
{
  WindowProp prop;
  prop.Width = 1280;
  prop.Height = 720;
  prop.Title = "B23CS1084";
  
  Application app(Backend::GLFW, prop);
  app.PushAssignmentProblem(std::make_unique<Problem1>());
  app.Run();

  return 0;
}
