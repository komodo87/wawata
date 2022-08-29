#include "window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

wawata::window::window(int width, int height, const char* title, bool fullscreen)
{
	id = (int*)glfwCreateWindow(width, height, title, fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent((GLFWwindow*)id);

	glewInit();

	// TODO: enable depth testing here (glEnable(GL_DEPTH_TEST) doesn't seem to work...)
	glEnable(GL_DEPTH_TEST);
}

bool wawata::window::is_open()
{
	return !glfwWindowShouldClose((GLFWwindow*)id);
}

void wawata::window::close()
{
	glfwSetWindowShouldClose((GLFWwindow*)id, true);
}

void wawata::window::set_clear_color(float red, float blue, float green)
{
	glClearColor(red, green, blue, 1.0);
}

void wawata::window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void wawata::window::display()
{
	glfwSwapBuffers((GLFWwindow*)id);
	glfwPollEvents();
}
