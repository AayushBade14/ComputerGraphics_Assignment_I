//-----------------------------------------------------------------------------
//  
//  Name: OpenGLRenderer.cpp
//
//  Desc: Implements the renderer interface using OpenGL as it's backend
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./OpenGLRenderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

//TO-DO: Remove the GLFW coupling here

void OpenGLRenderer::Init()
{
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "ERROR: GLAD::Init()" << std::endl;
    exit(1);
  }

  std::cout << "OpenGL initialized!" << std::endl;

  glEnable(GL_DEPTH_TEST);
}

void OpenGLRenderer::Shutdown()
{

}

void OpenGLRenderer::BeginFrame()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::EndFrame()
{

}

void OpenGLRenderer::SetViewport(int x, int y, int w, int h)
{
  glViewport(x, y, w, h);
}
