#pragma once
#include <string>
#include <vector>

#include "vec.hpp"

class Object
{
public:
  Object() {}

  void draw(int loc_a_vertex);
  void print();
	
	bool load_simple_obj(const std::string& filename);

private:
  std::vector<kmuvcl::math::vec3f> vb;     // vertices  
};
