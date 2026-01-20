#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "./stb_image.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

struct Shader{
  unsigned int ID;

  Shader(const char* vertexPath,const char* fragmentPath);
  ~Shader();

  void use();

  void setBool(std::string name,bool value) const;
  void setInt(std::string name,int value) const;
  void setFloat(std::string name,float value) const;

  void setVec2(std::string name,glm::vec2 &vector) const;
  void setVec2(std::string name,float x,float y) const;

  void setVec3(std::string name,glm::vec3 &vector) const;
  void setVec3(std::string name,float x,float y,float z) const;

  void setMat4(std::string name,glm::mat4 &matrix) const;
};

struct Texture{
  unsigned int ID;
  int val;
  std::string name;
  std::string type;

  Texture(const char* texPath,Shader &shader,std::string name,int val,std::string type);
  ~Texture()=default;

  void activate();
  void deactivate();
};
