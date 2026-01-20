//-----------------------------------------------------------------------------
//  
//  Name: OpenGLShader.cpp
//
//  Desc: An Shader interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#include "./OpenGLShader.h"
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <iostream>
#include <cstdlib>

OpenGLShader::OpenGLShader(const std::string& vertPath, const std::string& fragPath)
{
  std::string vCode = LoadFile(vertPath);
  std::string fCode = LoadFile(fragPath);
  unsigned int vert = CompileShader(vCode, true);
  unsigned int frag = CompileShader(fCode, false);
  CreateShaderProgram(vert, frag);
}

OpenGLShader::~OpenGLShader()
{
  glDeleteProgram(m_Id);
}

void OpenGLShader::Use()
{
  glUseProgram(m_Id);
}

void OpenGLShader::SetFloat(const std::string& name, float val)
{
  unsigned int loc = glGetUniformLocation(m_Id, name.c_str());
  glUniform1f(loc, val);
}

std::string OpenGLShader::LoadFile(const std::string& path)
{
  std::string code;
  std::ifstream file;

  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    file.open(path);  
    std::stringstream stream;
    stream << file.rdbuf();
    code = stream.str();
    file.close();
  }
  catch(const std::ifstream::failure& e)
  {
    std::cerr << "ERROR: Opening file: " << path << std::endl;
    exit(1);
  }

  return code;
}

unsigned int OpenGLShader::CompileShader(const std::string& srcCode, bool isVert)
{
  const char* code = srcCode.c_str();
  int success;
  char infoLog[512];
  unsigned int shader = isVert? glCreateShader(GL_VERTEX_SHADER) : glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(shader, 1, &code, nullptr);
  glCompileShader(shader);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
    glGetShaderInfoLog(shader, 512, nullptr, infoLog);
    std::cerr << "ERROR: Compiling " << (isVert? "vertex-shader" : "fragment-shader")
      << " -> " << infoLog << std::endl;
    exit(1);
  }
  
  return shader;
}

void OpenGLShader::CreateShaderProgram(unsigned int& vert, unsigned int& frag)
{
  m_Id = glCreateProgram();
  glAttachShader(m_Id, vert);
  glAttachShader(m_Id, frag);
  glLinkProgram(m_Id);

  int success;
  char infoLog[512];

  glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
  if(!success)
  {
    glGetProgramInfoLog(m_Id, 512, nullptr, infoLog);
    std::cerr << "ERROR: Linking shader program -> " << infoLog << std::endl;
    exit(1);
  }

  std::cout << "Shader program created successfully!" << std::endl;
}
