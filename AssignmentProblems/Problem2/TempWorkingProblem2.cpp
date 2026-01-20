#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../include/shader_texture.h"

#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define TITLE "B23CS1084"

void framebuffer_size_callback(GLFWwindow *window,int width,int height);
void processInput(GLFWwindow *window);

int main(void){
  if(glfwInit()<0){
    std::cout<<"ERROR::INITIALIZING_GLFW"<<std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH,
                                        WINDOW_HEIGHT,
                                        TITLE,
                                        NULL,
                                        NULL);

  if(!window){
    std::cout<<"ERROR::CREATING_WINDOW"<<std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<<"ERROR::INITIALIZING_GLAD"<<std::endl;
    glfwTerminate();
    return -1;
  }
  
  float vertices[] = {
    -1.0f,1.0f,0.0f, 1.0f,0.0f, 0.0f,
    -1.0f,0.0f,0.0f,  1.0f,0.0f, 0.0f,
    0.0f,1.0f,0.0f,   1.0f,0.0f, 0.0f
  };

  float vertices2[] = {
    0.0f,0.0f,0.0f,   0.0f,1.0f, 0.0f,
    1.0f,0.0f,0.0f,  0.0f,1.0f, 0.0f,
    0.0f,-1.0f,0.0f,   0.0f,1.0f, 0.0f,

    1.0f,0.0f,0.0f,  0.0f,1.0f, 0.0f,
    1.0f,-1.0f,0.0f, 0.0f,1.0f,0.0f,
    0.0f,-1.0f,0.0f,   0.0f,1.0f, 0.0f
  };

  Shader shader = Shader("../../vert.glsl","../../frag.glsl");
  unsigned int VBO,VAO;
  glGenBuffers(1,&VBO);
  glGenVertexArrays(1,&VAO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);

  unsigned int VBO1,VAO1;
  glGenBuffers(1,&VBO1);
  glGenVertexArrays(1,&VAO1);

  glBindVertexArray(VAO1);
  glBindBuffer(GL_ARRAY_BUFFER,VBO1);
  glBufferData(GL_ARRAY_BUFFER,sizeof(vertices2),vertices2,GL_STATIC_DRAW);

  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);

  glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

  while(!glfwWindowShouldClose(window)){
    glfwPollEvents();
    processInput(window);

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    
    shader.use();
    shader.setMat4("model",model);
    shader.setMat4("view",view);
    shader.setMat4("projection",projection);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);
    
    glBindVertexArray(VAO1);
    glDrawArrays(GL_TRIANGLES,0,6);
    glBindVertexArray(0);

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  glfwDestroyWindow(window);

  glDeleteBuffers(1,&VBO);
  glDeleteVertexArrays(1,&VAO);
  return 0;
}

void framebuffer_size_callback(GLFWwindow *window,int width,int height){
  glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window){

  if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
    glfwSetWindowShouldClose(window,true);
}

