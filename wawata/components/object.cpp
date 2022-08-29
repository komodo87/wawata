#include "object.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

wawata::components::object::object()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void wawata::components::object::update()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(float), mesh.data(), GL_DYNAMIC_DRAW);
}

void wawata::components::object::draw()
{
	glUseProgram(shader_program->id);

	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->id);

	glm::mat4 transform = glm::translate(glm::mat4(1.0), glm::vec3(position[0], position[1], position[2]));
	transform = glm::rotate(transform, rotation[0], glm::vec3(1.0, 0.0, 0.0));
	transform = glm::rotate(transform, rotation[1], glm::vec3(0.0, 1.0, 0.0));
	transform = glm::rotate(transform, rotation[2], glm::vec3(0.0, 0.0, 1.0));
	transform = glm::scale(transform, glm::vec3(scale[0], scale[1], scale[2]));
	glUniformMatrix4fv(glGetUniformLocation(shader_program->id, "transform"), 1, GL_FALSE, &transform[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, mesh.size() / 5 * 3);
}
