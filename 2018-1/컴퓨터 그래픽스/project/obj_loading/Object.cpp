#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

#include "Object.h"

extern kmuvcl::math::vec4f center_position_desk;
extern GLint loc_a_vertex;
extern GLint loc_a_normal;
extern GLint loc_a_texcoord;

extern GLint  loc_u_pvm_matrix;
extern GLint  loc_u_view_matrix;
extern GLint  loc_u_model_matrix;
extern GLint  loc_u_normal_matrix;

extern GLint  loc_u_light_vector;

extern GLint  loc_u_light_ambient;
extern GLint  loc_u_light_diffuse;
extern GLint  loc_u_light_specular;

extern GLint  loc_u_material_ambient;
extern GLint  loc_u_material_diffuse;
extern GLint  loc_u_material_specular;
extern GLint  loc_u_material_shininess;

extern GLint  loc_a_texcoord;
extern GLint  loc_u_texid;

extern float libert_ratio;


Group::Group(const std::string& name)
{
  m_name = name;

  m_vertices.clear();
  m_normals.clear();
  m_texcoords.clear();

  m_mtl_name = "Default";
}

Material::Material()
{
  m_name = "Default";

  m_ambient   = kmuvcl::math::vec4f(0.5f, 0.5f, 0.5f, 1.0f);
  m_diffuse   = kmuvcl::math::vec4f(0.5f, 0.5f, 0.5f, 1.0f);
  m_specular  = kmuvcl::math::vec4f(0.5f, 0.5f, 0.5f, 1.0f);
  m_shininess = 1.0f;
}

Material::Material(const std::string& name,
  kmuvcl::math::vec4f& ambient,
  kmuvcl::math::vec4f& diffuse,
  kmuvcl::math::vec4f& specular,
  float& shininess)
{
  m_name = name;

  m_ambient   = ambient;
  m_diffuse   = diffuse;
  m_specular  = specular;
  m_shininess = shininess;
}

void Object::draw(int loc_a_vertex, int loc_a_normal,
  int loc_u_material_ambient, int loc_u_material_diffuse,
  int loc_u_material_specular, int loc_u_material_shininess)
{
  for (size_t i=0; i<m_groups.size(); ++i)
  {
    Group& group = m_groups[i];

    Material& mtl = m_materials[group.m_mtl_name];
    kmuvcl::math::vec4f& ambient  = mtl.m_ambient;
    kmuvcl::math::vec4f& diffuse  = mtl.m_diffuse;
    kmuvcl::math::vec4f& specular = mtl.m_specular;
    float shininess              = 40.f;//mtl.m_shininess;

    glUniform4fv(loc_u_material_ambient, 1, ambient);
    glUniform4fv(loc_u_material_diffuse, 1, diffuse);
    glUniform4fv(loc_u_material_specular, 1, specular);
    glUniform1f(loc_u_material_shininess, shininess);

    glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, false, 0, group.m_vertices.data());
    glVertexAttribPointer(loc_a_normal, 3, GL_FLOAT, false, 0, group.m_normals.data());

    glEnableVertexAttribArray(loc_a_vertex);
    glEnableVertexAttribArray(loc_a_normal);

    glDrawArrays(GL_TRIANGLES, 0, group.m_vertices.size());

    glDisableVertexAttribArray(loc_a_vertex);
    glDisableVertexAttribArray(loc_a_normal);
  }
}
void Object::draw2(kmuvcl::math::mat4x4f mat_Model, kmuvcl::math::mat4x4f mat_Proj, kmuvcl::math::mat4x4f mat_View_inv)
{
  kmuvcl::math::mat4x4f mat_PVM, mat_Normal, mat_View;

  mat_View = kmuvcl::math::inverse(mat_View_inv);

  mat_PVM = mat_Proj * mat_View_inv * mat_Model;

  mat_Normal(0, 0) = mat_Model(0, 0);
  mat_Normal(0, 1) = mat_Model(0, 1);
  mat_Normal(0, 2) = mat_Model(0, 2);
  mat_Normal(1, 0) = mat_Model(1, 0);
  mat_Normal(1, 1) = mat_Model(1, 1);
  mat_Normal(1, 2) = mat_Model(1, 2);
  mat_Normal(2, 0) = mat_Model(2, 0);
  mat_Normal(2, 1) = mat_Model(2, 1);
  mat_Normal(2, 2) = mat_Model(2, 2);

  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);
  glUniformMatrix4fv(loc_u_model_matrix, 1, false, mat_Model);
  glUniformMatrix4fv(loc_u_view_matrix, 1, false, mat_View);
  glUniformMatrix3fv(loc_u_normal_matrix, 1, false, mat_Normal);

  for (size_t i=0; i<m_groups.size(); ++i)
  {
    Group& group = m_groups[i];

    Material& mtl = m_materials[group.m_mtl_name];
    kmuvcl::math::vec4f ambient  = kmuvcl::math::vec4f(0.5f*libert_ratio, 0.5f, 0.5f, 1.0f);
    kmuvcl::math::vec4f diffuse  = kmuvcl::math::vec4f(0.5f*libert_ratio, 0.5f, 0.5f, 1.0f);
    kmuvcl::math::vec4f specular = kmuvcl::math::vec4f(0.5f*libert_ratio, 0.5f, 0.5f, 1.0f);
    float shininess              = 40.0f;

    glUniform4fv(loc_u_material_ambient, 1, ambient);
    glUniform4fv(loc_u_material_diffuse, 1, diffuse);
    glUniform4fv(loc_u_material_specular, 1, specular);
    glUniform1f(loc_u_material_shininess, shininess);

    glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, false, 0, group.m_vertices.data());
    glVertexAttribPointer(loc_a_normal, 3, GL_FLOAT, false, 0, group.m_normals.data());

    glEnableVertexAttribArray(loc_a_vertex);
    glEnableVertexAttribArray(loc_a_normal);

    glDrawArrays(GL_TRIANGLES, 0, group.m_vertices.size());

    glDisableVertexAttribArray(loc_a_vertex);
    glDisableVertexAttribArray(loc_a_normal);
  }
}
void Object::draw3(kmuvcl::math::mat4x4f mat_Model, kmuvcl::math::mat4x4f mat_Proj, kmuvcl::math::mat4x4f mat_View_inv)
{
    GLfloat vertices[] = {
      -0.2, 0.2, 0.2,   0.2, 0.2, 0.2,   0.2,-0.2, 0.2,  -0.2,-0.2, 0.2,
      // back
      0.2, 0.2, -0.2,  -0.2, 0.2, -0.2,  -0.2,-0.2, -0.2,   0.2,-0.2, -0.2,
      // top
      -0.2, 0.2, -0.2,   0.2, 0.2, -0.2,   0.2, 0.2, 0.2,  -0.2, 0.2, 0.2,
      // bottom
      -0.2,-0.2, 0.2,   0.2,-0.2, 0.2,   0.2,-0.2, -0.2,  -0.2,-0.2, -0.2,
      // right
      0.2, 0.2, 0.2,   0.2, 0.2, -0.2,   0.2,-0.2, -0.2,   0.2,-0.2, 0.2,
      // left
      -0.2, 0.2, -0.2,  -0.2, 0.2, 0.2,  -0.2,-0.2, 0.2,  -0.2,-0.2, -0.2,
    };
    GLfloat texcoords[] = {
      // front
      0,5,  5,5,  5,0,  0,0,
      // back
      0,5,  5,5,  5,0,  0,0,
      // top
      0,5,  5,5,  5,0,  0,0,
      // bottom
      0,5,  5,5,  5,0,  0,0,
      // right
      0,5,  5,5,  5,0,  0,0,
      // left
      0,5,  5,5,  5,0,  0,0,
    };
    GLushort indices[] = {
      //front
      0, 3, 2,   2, 1, 0,
      //back
      4, 7, 6,   6, 5, 4,
      // top
      8,11,10,  10, 9, 8
    };
    GLfloat normals[] = {
      0,0,1,   0,0,1,    0,0,1,    0,0,1,
      0,0,-1,  0,0,-1,   0,0,-1,   0,0,-1,
      0,1,0,   0,1,0,    0,1,0,    0,1,0,
      0,-1,0,  0,-1,0,   0,-1,0,  0,-1,0,
      1,0,0,  1,0,0,     1,0,0,   1,0,0,
      -1,0,0, -1,0,0,    -1,0,0,  -1,0,0,
    };

    kmuvcl::math::mat4x4f mat_PVM, mat_Normal, mat_View;

    mat_View = kmuvcl::math::inverse(mat_View_inv);

    mat_PVM = mat_Proj * mat_View_inv * mat_Model;

    mat_Normal(0, 0) = mat_Model(0, 0);
    mat_Normal(0, 1) = mat_Model(0, 1);
    mat_Normal(0, 2) = mat_Model(0, 2);
    mat_Normal(1, 0) = mat_Model(1, 0);
    mat_Normal(1, 1) = mat_Model(1, 1);
    mat_Normal(1, 2) = mat_Model(1, 2);
    mat_Normal(2, 0) = mat_Model(2, 0);
    mat_Normal(2, 1) = mat_Model(2, 1);
    mat_Normal(2, 2) = mat_Model(2, 2);

    glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);
    glUniformMatrix4fv(loc_u_model_matrix, 1, false, mat_Model);
    glUniformMatrix4fv(loc_u_view_matrix, 1, false, mat_View);
    glUniformMatrix3fv(loc_u_normal_matrix, 1, false, mat_Normal);

    kmuvcl::math::vec4f ambient  = kmuvcl::math::vec4f(0.2f, 0.2f, 0.2f, 1.0f);
    kmuvcl::math::vec4f diffuse  = kmuvcl::math::vec4f(0.2f, 0.2f, 0.2f, 1.0f);
    kmuvcl::math::vec4f specular = kmuvcl::math::vec4f(0.2f, 0.2f, 0.2f, 1.0f);
    float shininess              = 40.0f;

    glUniform4fv(loc_u_material_ambient, 1, ambient);
    glUniform4fv(loc_u_material_diffuse, 1, diffuse);
    glUniform4fv(loc_u_material_specular, 1, specular);
    glUniform1f(loc_u_material_shininess, shininess);


    glVertexAttribPointer(loc_a_texcoord, 2, GL_FLOAT, GL_FALSE, 0, texcoords);
    glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(loc_a_normal, 3, GL_FLOAT, GL_FALSE, 0, normals);

    glEnableVertexAttribArray(loc_a_vertex);
    glEnableVertexAttribArray(loc_a_normal);
    glEnableVertexAttribArray(loc_a_texcoord);

    glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLushort), GL_UNSIGNED_SHORT, indices);

    glDisableVertexAttribArray(loc_a_vertex);
    glDisableVertexAttribArray(loc_a_normal);
    glDisableVertexAttribArray(loc_a_texcoord);
  }
void Object::print()
{
  for (size_t i = 0; i < m_groups.size(); ++i)
  {
    Group& group = m_groups[i];

    Material& mtl = m_materials[group.m_mtl_name];
    kmuvcl::math::vec4f& ambient = mtl.m_ambient;
    kmuvcl::math::vec4f& diffuse = mtl.m_diffuse;
    kmuvcl::math::vec4f& specular = mtl.m_specular;
    float& shininess = mtl.m_shininess;

    std::cout << "Group: " << group.m_name << std::endl;

    std::cout << "\tUsemtl: " << group.m_mtl_name << std::endl;
    std::cout << "\t\tAmbient: " << ambient[0] << " " << ambient[1] << " " << ambient[2] << std::endl;
    std::cout << "\t\tDiffuse: " << diffuse[0] << " " << diffuse[1] << " " << diffuse[2] << std::endl;
    std::cout << "\t\tSpecular: " << specular[0] << " " << specular[1] << " " << specular[2] << std::endl;
    std::cout << "\t\tShininess: " << shininess << std::endl;

    std::cout << "\tVertices: " << group.m_vertices.size() << std::endl;
    for (size_t i = 0; i < group.m_vertices.size(); ++i)
    {
      std::cout << "\t\t" << group.m_vertices[i][0] << " " << group.m_vertices[i][1] << " " << group.m_vertices[i][2] << std::endl;

    }
    std::cout << "\tTexcoord: " << group.m_texcoords.size() << std::endl;
    for (size_t i = 0; i < group.m_texcoords.size(); ++i)
    {
      std::cout << "\t\t" << group.m_texcoords[i][0] << " " << group.m_texcoords[i][1] << std::endl;
    }

    std::cout << "\tNormal: " << group.m_normals.size() << std::endl;
    for (size_t i = 0; i < group.m_normals.size(); ++i)
    {
      std::cout << "\t\t" << group.m_normals[i][0] << " " << group.m_normals[i][1] << " " << group.m_normals[i][2] << std::endl;
    }
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

  std::string type_str;
  char slash;				// get only on character '\'

  std::string line;
  std::locale loc;

  bool has_texcoord = false;
  bool has_normal   = false;;

	std::vector<kmuvcl::math::vec3f> vertices;
	std::vector<kmuvcl::math::vec2f> texcoords;
	std::vector<kmuvcl::math::vec3f> normals;

  m_groups.push_back(Group("Default"));
  m_materials["Default"] = Material();

  PATH = filename.substr(0, filename.find_last_of('/'));

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
    else if (line.substr(0, 7) == "mtllib ") // open material file
    {
      std::string mtl_filename;
      ss >> type_str >> mtl_filename;

      std::string fullpath = PATH + '/' + mtl_filename;
      load_simple_mtl(fullpath);
    }
		else if (line.substr(0, 2) == "v ")   // vertex
		{
			kmuvcl::math::vec3f vertex;
			ss >> type_str >> vertex[0] >> vertex[1] >> vertex[2];
			vertices.push_back(vertex);
		}
		else if (line.substr(0, 3) == "vt ")  // texture coordinate
		{
			kmuvcl::math::vec2f texcoord;
			ss >> type_str >> texcoord[0] >> texcoord[1];
			texcoords.push_back(texcoord);

      has_texcoord = true;
		}
		else if (line.substr(0, 3) == "vn ")  // vertex normal
		{
			kmuvcl::math::vec3f norm;
			ss >> type_str >> norm[0] >> norm[1] >> norm[2];
			normals.push_back(norm);

      has_normal = true;
		}
    else if (line.substr(0, 2) == "g ")   // group
    {
      std::string group_name;
      ss >> type_str >> group_name;

      m_groups.push_back(Group(group_name));
    }
    else if (line.substr(0, 7) == "usemtl ") // materail
    {
      std::string mtl_name;
      ss >> type_str >> mtl_name;

      m_groups.back().m_mtl_name = mtl_name;
    }
		// faces
		else if (line.substr(0, 2) == "f ")
		{
      Group& group = m_groups.back();

      std::vector<std::string> lines;

      kmuvcl::math::vec3i vertex_idx;
      kmuvcl::math::vec3i texcoord_idx;
      kmuvcl::math::vec3i normal_idx;

      if (!has_texcoord && !has_normal) // f v
      {
        ss >> type_str >> vertex_idx[0] >> vertex_idx[1] >> vertex_idx[2];

        group.m_vertices.push_back(vertices[vertex_idx[0] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[1] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[2] - 1]);
      }
      else if (has_texcoord && !has_normal) // f v/vt
      {
        ss >> type_str >>
          vertex_idx[0] >> slash >> texcoord_idx[0] >>
          vertex_idx[1] >> slash >> texcoord_idx[1] >>
          vertex_idx[2] >> slash >> texcoord_idx[2];

        group.m_vertices.push_back(vertices[vertex_idx[0] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[1] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[2] - 1]);

        group.m_texcoords.push_back(texcoords[texcoord_idx[0] - 1]);
        group.m_texcoords.push_back(texcoords[texcoord_idx[1] - 1]);
        group.m_texcoords.push_back(texcoords[texcoord_idx[2] - 1]);
      }
      else if (!has_texcoord && has_normal) // f v//vn
      {
        ss >> type_str >>
          vertex_idx[0] >> slash >> slash >> normal_idx[0] >>
          vertex_idx[1] >> slash >> slash >> normal_idx[1] >>
          vertex_idx[2] >> slash >> slash >> normal_idx[2];

        group.m_vertices.push_back(vertices[vertex_idx[0] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[1] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[2] - 1]);

        group.m_normals.push_back(normals[normal_idx[0] - 1]);
        group.m_normals.push_back(normals[normal_idx[1] - 1]);
        group.m_normals.push_back(normals[normal_idx[2] - 1]);
      }
      else if (has_texcoord && has_normal) // f v/vt/vn
      {
        ss >> type_str >>
          vertex_idx[0] >> slash >> texcoord_idx[0] >> slash >> normal_idx[0] >>
          vertex_idx[1] >> slash >> texcoord_idx[1] >> slash >> normal_idx[1] >>
          vertex_idx[2] >> slash >> texcoord_idx[2] >> slash >> normal_idx[2];

        group.m_vertices.push_back(vertices[vertex_idx[0] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[1] - 1]);
        group.m_vertices.push_back(vertices[vertex_idx[2] - 1]);

        group.m_texcoords.push_back(texcoords[texcoord_idx[0] - 1]);
        group.m_texcoords.push_back(texcoords[texcoord_idx[1] - 1]);
        group.m_texcoords.push_back(texcoords[texcoord_idx[2] - 1]);

        group.m_normals.push_back(normals[normal_idx[0] - 1]);
        group.m_normals.push_back(normals[normal_idx[1] - 1]);
        group.m_normals.push_back(normals[normal_idx[2] - 1]);
      }
    }
	}

	std::cout << "finished to read: " << filename << std::endl;
	return true;
}

bool Object::load_simple_mtl(const std::string& filename)
{
  std::ifstream file(filename.c_str());

  if (!file.is_open())
  {
    std::cerr << "failed to open file: " << filename << std::endl;
    return false;
  }

  float r, g, b;
  std::string type_str;

  std::string line;
  std::locale loc;

  std::string           name;
  kmuvcl::math::vec4f   ambient;
  kmuvcl::math::vec4f   diffuse;
  kmuvcl::math::vec4f   specular;
  float                 shininess;

  bool is_name = false;
  bool is_ka   = false;
  bool is_kd   = false;
  bool is_ks   = false;
  bool is_ns   = false;

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
    else if (line.substr(0, 7) == "newmtl ")
    {
        ss >> type_str >> name;
        is_name = true;
    }
    else if (line.substr(0, 3) == "Ka ")
    {
      ss >> type_str >> r >> g >> b;
      ambient = kmuvcl::math::vec4f(r, g, b, 1.0f);
      is_ka = true;
    }
    else if (line.substr(0, 3) == "Kd ")
    {
      ss >> type_str >> r >> g >> b;
      diffuse = kmuvcl::math::vec4f(r, g, b, 1.0f);
      is_kd = true;
    }
    else if (line.substr(0, 3) == "Ks ")
    {
      ss >> type_str >> r >> g >> b;
      specular = kmuvcl::math::vec4f(r, g, b, 1.0f);
      is_ks = true;
    }
    else if (line.substr(0, 3) == "Ns ")
    {
      ss >> type_str >> shininess;
      is_ns = true;
    }

    if (is_name == true && is_ka == true && is_kd == true && is_ks == true && is_ns == true)
    {
      m_materials[name] = Material(name, ambient, diffuse, specular, shininess);

      is_name = false;
      is_ka = false;
      is_kd = false;
      is_ks = false;
      is_ns = false;
    }
  }
}
