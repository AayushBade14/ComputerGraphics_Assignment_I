//-----------------------------------------------------------------------------
//  
//  Name: OpenGLShader.h
//
//  Desc: An Shader interface implementation for OpenGL
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include "../../../Core/Graphics/Shader.h"

class OpenGLShader : public Shader
{

  private:

    unsigned int m_Id;
    
    std::string LoadFile(const std::string& path);
    unsigned int CompileShader(unsigned int srcCode, bool isVert);
    void CreateShaderProgram(unsigned int& vert, unsigned int& frag);
  
  public:

    OpenGLShader(const std::string& vertPath, const std::string& fragPath);

    ~OpenGLShader();

    void Use() override;
    void SetFloat(const std::string& name, float val) override;
};
