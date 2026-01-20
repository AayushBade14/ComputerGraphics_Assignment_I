cmake_minimum_required(VERSION 3.10)
project(
  cg
  VERSION 1.0
  DESCRIPTION "Computer graphics assignment 1 - B23CS1084"
  LANGUAGES C CXX
)

include_directories(
  ../../Vendor/glad/include
  ../include
)

include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.9
)
FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

add_subdirectory(../../Vendor/glm
  ${CMAKE_BINARY_DIR}/glm
)

file(GLOB_RECURSE INCLUDE_SRC ../include/*.cpp ../include/*.h)
file(GLOB_RECURSE GLAD_SRC ../../Vendor/glad/src/*.c)

add_executable(
  cg
  ${INCLUDE_SRC}
  ${GLAD_SRC}
  TempWorkingProblem2.cpp
)

target_link_libraries(
  cg
  PRIVATE
  glfw
  glm::glm
  OpenGL::GL
)

