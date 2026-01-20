#include "./shader_texture.h"

Shader::Shader(const char* vertexPath,const char* fragmentPath){
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try{
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    std::stringstream vShaderStream,fShaderStream;
    
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  }
  catch(std::ifstream::failure &e){
    std::cout<<"ERROR::READING_BUFFER::SHADER_BUFFER"<<std::endl;
  }

  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  unsigned int vertex,fragment;
  int success;
  char infoLog[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex,1,&vShaderCode,NULL);
  glCompileShader(vertex);

  glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
  if(!success){
    glGetShaderInfoLog(vertex,512,NULL,infoLog);
    std::cout<<"ERROR::COMPILING_SHADER::VERTEX_SHADER-> "<<infoLog<<std::endl;
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment,1,&fShaderCode,NULL);
  glCompileShader(fragment);

  glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
  if(!success){
    glGetShaderInfoLog(fragment,512,NULL,infoLog);
    std::cout<<"ERORR::COMPILING_SHADER::FRAGMENT_SHADER-> "<<infoLog<<std::endl;
  }

  ID = glCreateProgram();
  glAttachShader(ID,vertex);
  glAttachShader(ID,fragment);
  glLinkProgram(ID);

  glGetProgramiv(ID,GL_LINK_STATUS,&success);
  if(!success){
    glGetProgramInfoLog(ID,512,NULL,infoLog);
    std::cout<<"ERROR::LINKING_SHADER::SHADER_PROGRAM-> "<<infoLog<<std::endl;
  }

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

Shader::~Shader(){
  glDeleteProgram(ID);
}

void Shader::use(){
  glUseProgram(ID);
}

void Shader::setBool(std::string name,bool value) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform1i(loc,(int)value);
}

void Shader::setInt(std::string name,int value) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform1i(loc,value);
}

void Shader::setFloat(std::string name,float value) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform1f(loc,value);
}

void Shader::setVec2(std::string name,glm::vec2 &vector) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform2fv(loc,1,&vector[0]);
}

void Shader::setVec2(std::string name,float x,float y) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform2f(loc,x,y);
}

void Shader::setVec3(std::string name,glm::vec3 &vector) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform3fv(loc,1,&vector[0]);
}

void Shader::setVec3(std::string name,float x,float y,float z) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniform3f(loc,x,y,z);
}

void Shader::setMat4(std::string name,glm::mat4 &matrix) const{
  unsigned int loc = glGetUniformLocation(ID,name.c_str());
  glUniformMatrix4fv(loc,1,GL_FALSE,glm::value_ptr(matrix));
}

Texture::Texture(const char* texPath,Shader &shader,std::string name,int val,std::string type){
  
  this->val = val;
  this->name = name;
  this->type = type;
  
  GLuint FLAG = GL_RGB;

  if(type == "PNG")
    FLAG = GL_RGBA;
  else
    FLAG = GL_RGB;

  glGenTextures(1,&(this->ID));
  glBindTexture(GL_TEXTURE_2D,this->ID);

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

  stbi_set_flip_vertically_on_load(true);

  int width,height,nrChannels;
  unsigned char* data = stbi_load(texPath,&width,&height,&nrChannels,0);
  if(data){
    glTexImage2D(GL_TEXTURE_2D,0,FLAG,width,height,0,FLAG,GL_UNSIGNED_BYTE,data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else{
    std::cout<<"ERROR::LOADING_TEXTURE-> "<<val<<std::endl;
  }
  stbi_image_free(data);

  shader.use();
  shader.setInt(name,val);
}

void Texture::activate(){
  glActiveTexture(GL_TEXTURE0 + (this->val));
  glBindTexture(GL_TEXTURE_2D,this->ID);
}

void Texture::deactivate(){
  glBindTexture(GL_TEXTURE_2D,0);
}
