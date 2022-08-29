#pragma once

namespace wawata
{
	namespace entities
	{
		struct shader_entity;
		struct shader_program_entity;
	}
}

struct wawata::entities::shader_entity
{
	unsigned int id;
};

struct wawata::entities::shader_program_entity
{
	unsigned int id;
	virtual void attach_shader(wawata::entities::shader_entity& shader){}
};
