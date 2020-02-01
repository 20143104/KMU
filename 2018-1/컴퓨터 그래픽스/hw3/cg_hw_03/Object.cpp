#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

#include "Object.h"

void Object::draw(int loc_a_vertex)
{
	glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, false, 0, &vb[0]);
	
	glEnableVertexAttribArray(loc_a_vertex);
	
	glDrawArrays(GL_TRIANGLES, 0, vb.size());

	glDisableVertexAttribArray(loc_a_vertex);	
}

void Object::print()
{
	for (size_t i=0; i<vb.size(); ++i)
  {
    const kmuvcl::math::vec3f& p = vb[i];

    std::cout << "v " << p(0) << " " << p(1) << " " << p(2) << std::endl;
  }
}

bool Object::load_simple_obj(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "failed to open file: " << filename << std::endl;
		return false;
	}

	Object* obj = new Object();

	std::vector<kmuvcl::math::vec3f> tmp_vertices;
	std::vector<kmuvcl::math::vec2f> tmp_texcoords;
	std::vector<kmuvcl::math::vec3f> tmp_normals;

	std::string line;
	std::locale loc;

	float x, y, z;
	std::string type_str;
	char slash;				// get only on character '\'

	std::stringstream ss;

	while (!file.eof())
	{
		std::getline(file, line);

		ss.clear();
		ss.str(line);

		// comment or space		
		if (line[0] == '#' || std::isspace(line[0], loc))
		{
			continue; // skip
		}
		// vertex
		else if (line.substr(0, 2) == "v ")
		{
			kmuvcl::math::vec3f vertex;
			ss >> type_str >> vertex(0) >> vertex(1) >> vertex(2);
			tmp_vertices.push_back(vertex);
		}
		// texture coordinate
		else if (line.substr(0, 3) == "vt ")
		{
			kmuvcl::math::vec2f texcoord;
			ss >> type_str >> texcoord(0) >> texcoord(1);
			tmp_texcoords.push_back(texcoord);
		}
		// vertex normal
		else if (line.substr(0, 3) == "vn ")
		{
			kmuvcl::math::vec3f norm;
			ss >> type_str >> norm(0) >> norm(1) >> norm(2);
			tmp_normals.push_back(norm);
		}
		// faces
		else if (line.substr(0, 2) == "f ")
		{
			kmuvcl::math::vec3u vert_idx;
			kmuvcl::math::vec3u coord_idx;

			ss >> type_str >> vert_idx(0) >> slash >> coord_idx(0) >>
				vert_idx(1) >> slash >> coord_idx(1) >>
				vert_idx(2) >> slash >> coord_idx(2);

			vb.push_back(tmp_vertices[vert_idx(0) - 1]);
			vb.push_back(tmp_vertices[vert_idx(1) - 1]);
			vb.push_back(tmp_vertices[vert_idx(2) - 1]);
		}
	}
	
	std::cout << "finished to read: " << filename << std::endl;
	return true;
}
