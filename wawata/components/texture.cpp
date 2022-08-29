#include "texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

wawata::components::texture::texture()
{
	glGenTextures(1, (GLuint*)&id);
}

bool wawata::components::texture::load(const char* filepath, unsigned int repeat_method, bool transparency, bool interpolate)
{
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeat_method);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeat_method);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, interpolate ? GL_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, interpolate ? GL_LINEAR : GL_NEAREST);

	int tex_width, tex_height, num_channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* tex_data = stbi_load(filepath, &tex_width, &tex_height, &num_channels, 0);
	if(!tex_data)
	{
		return false;
		stbi_image_free(tex_data);
	}

	int channels = transparency ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, channels, tex_width, tex_height, 0, channels, GL_UNSIGNED_BYTE, tex_data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(tex_data);
	return true;
}
