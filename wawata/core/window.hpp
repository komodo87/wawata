#include "keycodes.hpp"

namespace wawata
{
	struct window;
}

struct wawata::window
{
	window(int width, int height, const char* title, bool fullscreen = false);
	int* id;

	bool is_open();
	void close();

	bool is_key_pressed(unsigned int keycode);
	bool was_key_tapped(unsigned int keycode);

	void set_clear_color(float red, float green, float blue);
	void clear();
	void display();
};
