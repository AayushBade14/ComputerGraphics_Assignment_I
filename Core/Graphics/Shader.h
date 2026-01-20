//-----------------------------------------------------------------------------
//  
//  Name: Shader.h
//
//  Desc: Defines an interface for the Shader class
//
//  Author: Aayush Bade 2026 (aayushbade14.github.io/Portfolio)
//
//-----------------------------------------------------------------------------

#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader
{

  public:

    virtual ~Shader() = default;

    virtual void Use() = 0;

    virtual void SetFloat(const std::string& name, float val);
    //virtual void SetInt(const std::string& name, int val);
    //virtual void SetBool(const std::string& name, bool val);
    //virtual void SetMat4(const std::string& name, const glm::mat4& mat);
};
