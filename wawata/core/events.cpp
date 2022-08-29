#include "window.hpp"
#include <GLFW/glfw3.h>

bool wawata::window::is_key_pressed(unsigned int keycode)
{
	return glfwGetKey((GLFWwindow*)id, keycode);
}

bool key_last_pressed[GLFW_KEY_LAST];
bool wawata::window::was_key_tapped(unsigned int keycode)
{
	if(!glfwGetKey((GLFWwindow*)id, keycode))
	{
		key_last_pressed[keycode] = false;
		return false;
	}

	if(key_last_pressed[keycode])
	{
		key_last_pressed[keycode] = true;
		return false;
	}

	key_last_pressed[keycode] = true;
	return true;
}
