#ifndef MAIN_H
#define MAIN_H
#include "glad.h"
#include "glfw3.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "render.h"
#include "camera.h"

#include <iostream>
#include <filesystem>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window, Camera camera);
GLFWwindow* windowInit();

#endif // MAIN_H
