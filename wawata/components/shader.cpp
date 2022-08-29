#include "shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

wawata::components::shader::shader(unsigned int shader_type)
{
	id = glCreateShader(shader_type);
}

bool wawata::components::shader::load(const char* filepath)
{
	std::ifstream shader_file;
	shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream shader_stream;

	try
	{
		shader_file.open(filepath);
		shader_stream << shader_file.rdbuf();
		shader_file.close();
	}
	catch(const std::exception& error)
	{
		std::cerr << "wawata: unable to open '" << filepath << "'\n";
		std::cout << error.what();

		return false;
	}
	
	std::string shader_string = shader_stream.str();
	const char* shader_code = shader_string.c_str();

	glShaderSource(id, 1, &shader_code, NULL);
	glCompileShader(id);

	int success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	return !success ? false : true;
}

bool wawata::components::shader_program::link()
{
	glLinkProgram(id);

	int success;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if(!success)
	{
		return false;
	}

	glUniform1i(glGetUniformLocation(id, "texture_index"), 0);
	return true;
}

void wawata::components::shader::destroy()
{
	glDeleteShader(id);
}

wawata::components::shader_program::shader_program()
{
	id = glCreateProgram();
}

void wawata::components::shader_program::attach_shader(wawata::entities::shader_entity& shader)
{
	glAttachShader(id, shader.id);
}

void wawata::components::shader_program::update_camera()
{
	glm::mat4 perspective = glm::perspective(camera->fov, (float)(4 / 3), camera->render_range[0], camera->render_range[1]);
	glUniformMatrix4fv(glGetUniformLocation(id, "perspective"), 1, GL_FALSE, &perspective[0][0]);
	glm::mat4 view = glm::lookAt(glm::vec3(camera->position[0], camera->position[1], camera->position[2]), glm::vec3(camera->look_to[0], camera->look_to[1], camera->look_to[2]), glm::vec3(0.0, 1.0, 0.0));
	glUniformMatrix4fv(glGetUniformLocation(id, "view"), 1, GL_FALSE, &view[0][0]);
}
