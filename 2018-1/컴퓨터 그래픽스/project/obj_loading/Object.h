#pragma once
#include <string>
#include <vector>
#include <map>

#include "vec.hpp"

struct Group
{
public:
  Group(const std::string& name);

public:
  std::string                         m_name;

  std::vector<kmuvcl::math::vec3f>    m_vertices;
  std::vector<kmuvcl::math::vec3f>    m_normals;
  std::vector<kmuvcl::math::vec2f>    m_texcoords;
  std::string                         m_mtl_name;
};

struct Material
{
public:
  Material();
  Material(const std::string& name,
    kmuvcl::math::vec4f& ambient,
    kmuvcl::math::vec4f& diffuse,
    kmuvcl::math::vec4f& specular,
    float& shininess);

public:
  std::string           m_name;

  kmuvcl::math::vec4f   m_ambient;
  kmuvcl::math::vec4f   m_diffuse;
  kmuvcl::math::vec4f   m_specular;
  float                 m_shininess;
};

class Object
{
public:
  Object() {}

  void draw(int loc_a_vertex, int loc_a_normal,
    int loc_u_material_ambient, int loc_u_material_diffuse,
    int loc_u_material_specular, int loc_u_material_shininess);
  void draw2(kmuvcl::math::mat4x4f mat_Model, kmuvcl::math::mat4x4f mat_Proj,kmuvcl::math::mat4x4f mat_View_inv);
  void draw3(kmuvcl::math::mat4x4f mat_Model, kmuvcl::math::mat4x4f mat_Proj,kmuvcl::math::mat4x4f mat_View_inv);
  void print();

	bool load_simple_obj(const std::string& filename);
  bool load_simple_mtl(const std::string& filename);

private:
  std::string PATH;
  std::vector<Group>              m_groups;
  std::map<std::string, Material> m_materials;
};
