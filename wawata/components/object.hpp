#pragma once

#include "../entities/object.hpp"
#include "../entities/texture.hpp"
#include <vector>

namespace wawata
{
	namespace components
	{
		struct object;
	}
}

struct wawata::components::object : wawata::entities::object_entity
{
	object();

	std::vector<float> mesh;

	float position[3] = {0.0, 0.0, 0.0};
	float rotation[3] = {0.0, 0.0, 0.0};
	float scale[3] = {1.0, 1.0, 1.0};

	unsigned int vbo, vao;
	wawata::entities::texture_entity* texture = nullptr;

	void update();
	void draw();
};
