#pragma once

#include "shader.hpp"

namespace wawata
{
	namespace entities
	{
		struct object_entity;
	}
}

struct wawata::entities::object_entity
{
	unsigned int id;
	virtual void draw(){}
	wawata::entities::shader_program_entity* shader_program = nullptr;
};
