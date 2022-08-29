#pragma once

#include "../entities/shader.hpp"
#include "camera.hpp"

#define WAW_SHADER_VERTEX 0x8B31
#define WAW_SHADER_FRAGMENT 0x8B30

namespace wawata
{
	namespace components
	{
		struct shader;
		struct shader_program;
	}
}

struct wawata::components::shader : wawata::entities::shader_entity
{
	shader(unsigned int shader_type);
	bool load(const char* filepath);
	void destroy();
};

struct wawata::components::shader_program : wawata::entities::shader_program_entity
{
	shader_program();
	void attach_shader(wawata::entities::shader_entity& shader);
	bool link();
	wawata::components::camera* camera = nullptr;
	void update_camera();
};
