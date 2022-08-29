#pragma once

#include "../entities/texture.hpp"

#define WAW_TEXTURE_TILED 0x2901
#define WAW_TEXUTRE_MIRRORED 0x8370

namespace wawata
{
	namespace components
	{
		struct texture;
	}
}

struct wawata::components::texture : wawata::entities::texture_entity
{
	texture();
	bool load(const char* filepath, unsigned int repeat_method = WAW_TEXTURE_TILED, bool transparency = false, bool interpolate = true);
};
