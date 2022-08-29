#include "loadobj.hpp"
#include <fstream>
#include <sstream>

std::vector<float> wawata::modules::loadobj(const char* filepath)
{
	std::vector<float> mesh;

	std::fstream obj_file;
	obj_file.open(filepath);

	if(obj_file.is_open())
	{
		std::string line;

		std::vector<float> vertices;
		std::vector<float> texture_coords;

		while(getline(obj_file, line))
		{
			if(line.substr(0, 2) == "v ")
			{
				std::string vertex;
				std::stringstream vert_stream(line);

				getline(vert_stream, vertex, *" ");
				while(getline(vert_stream, vertex, *" "))
				{
					vertices.push_back(std::atof(vertex.c_str()));
				}
			}
			
			if(line.substr(0, 2) == "vt")
			{
				std::string texture_coord;
				std::stringstream tex_coord_stream(line);

				getline(tex_coord_stream, texture_coord, *" ");
				while(getline(tex_coord_stream, texture_coord, *" "))
				{
					texture_coords.push_back(std::atof(texture_coord.c_str()));
				}
			}
		}

		obj_file.close();
		obj_file.open(filepath);

		std::vector<int> vertex_indices;
		std::vector<int> texture_indices;

		while(getline(obj_file, line))
		{
			if(line.substr(0, 2) == "f ")
			{
				std::string face;
				std::stringstream face_stream(line);

				getline(face_stream, face, *" ");
				while(getline(face_stream, face, *" "))
				{
					std::string face_vertex;
					std::stringstream face_vertex_stream(face);

					getline(face_vertex_stream, face_vertex, *"/");
					vertex_indices.push_back((std::stoi(face_vertex) - 1) * 3);

					while(getline(face_vertex_stream, face_vertex, *"/"));
					texture_indices.push_back((std::stoi(face_vertex ) - 1) * 2);
				}
			}
		}

		obj_file.close();

		for(int offset = 0; offset < vertex_indices.size(); offset++)
		{
			mesh.push_back(vertices[vertex_indices[offset]]);
			mesh.push_back(vertices[vertex_indices[offset] + 1]);
			mesh.push_back(vertices[vertex_indices[offset] + 2]);
			mesh.push_back(0);
			mesh.push_back(0);
		}

		for(int offset = 0; offset < texture_indices.size(); offset++)
		{
			mesh[(offset * 5) + 3] = texture_coords[texture_indices[offset]];
			mesh[(offset * 5) + 4] = texture_coords[texture_indices[offset] + 1];
		}
	}
	else
	{
		return {};
	}

    return mesh;
}
