#include "engine.hpp"
#include <GLFW/glfw3.h>

bool wawata::init(int context_version_major, int context_version_minor, int profile)
{
	if(!glfwInit())
	{
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, context_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, context_version_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, profile);

	return true;
}

void wawata::terminate()
{
	glfwTerminate();
}

double wawata::get_time()
{
	return glfwGetTime();
}
