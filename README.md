# ComputerGraphics_Assignment_I
Computer Graphics Course Assignment

## Problem1 Screenshot
![Problem1-Screenshot](./Problem1_B23CS1084.png)
## Problem2 Screenshot
![Problem2-Screenshot](./Problem2_B23CS1084.png)

The main rendering engine is a work in progress, for respecting the deadline of the assignment I have also added temporary implementation for the two problems. Which will be soon replaced with the proper engine abstractions.

## Current Features
- Window interface which has swappable backend for using GLFW or SDL
- InputSystem interface which has a swappable backend for using GLFW or SDL
- EventBus this is the bus for transmitting events to the user application from the window and input system which makes use of the Observer pattern
- Renderer interface which has swappable backend for using OpenGL, Vulkan and DirectX
- Graphics Entities like shaders, buffers and vertex arrays also have an interface with a swappable backend for different graphics apis.

## Cloning the repo
```
git clone https://github.com/AayushBade14/ComputerGraphics_Assignment_I.git

cd ComputerGraphics_Assignment_I
```
## Running problem1
```
cd AssignmentProblems/Problem1
mkdir build
cd build
cmake ..
cmake --build .
./cg
```
## Running problem2
```
cd AssignmentProblems/Problem2
mkdir build
cd build
cmake ..
cmake --build .
./cg
```
