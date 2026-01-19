cmake_minimum_required(VERSION 3.10)
project(
  cg
  VERSION 1.0
  DESCRIPTION "Computer graphics assignment-I done by: Aayush Bade (B23CS1084)"
  LANGUAGES C CXX
)

# Include directories
include_directories(
  Vendor/glad/include
  Vendor/glm
)

# Fetch GLFW from remote repo
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.9
)
FetchContent_MakeAvailable(glfw)

# Get source files using global-recursion
file(GLOB_RECURSE CORE_SRC Core/*.cpp Core/*.h)
file(GLOB_RECURSE PLATFORM_SRC Platform/*.cpp Platform/*.h)
file(GLOB_RECURSE APP_SRC App/*.cpp App/*.h)
file(GLOB_RECURSE PROBLEM_SRC AssignmentProblems/*.cpp AssignmentProblems/*.h)
file(GLOB_RECURSE VENDOR_SRC Vendor/glad/src/*.c)

# Make executable
add_executable(
  cg
  ${CORE_SRC}
  ${PLATFORM_SRC}
  ${APP_SRC}
  ${PROBLEM_SRC}
  ${VENDOR_SRC}
  main.cpp
)

# Link everything
target_link_libraries(
  cg
  glfw
)
