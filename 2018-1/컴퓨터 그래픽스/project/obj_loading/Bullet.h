#pragma once
#include "operator.hpp"
#include <vector>
#include <cmath>

extern GLint loc_a_vertex;
extern GLint loc_a_normal;
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

float libert_ratio = 1.0f;
float jesus_ratio = 1.0f;
float alucy_ratio = 1.0f;
float statue_ratio = 1.0f;

class Bullet
{
public:
  kmuvcl::math::vec4f front_dir;
  kmuvcl::math::vec3f pos;
  float ratio;
  kmuvcl::math::vec4f center_position;

  Bullet(kmuvcl::math::vec4f bfd, kmuvcl::math::vec3f bp, float br, kmuvcl::math::vec4f bcp)
  {
      front_dir = bfd;
      pos = bp;
      ratio = br;
      center_position = bcp;
  }
  int collision(kmuvcl::math::vec4f libert_center_position,
                kmuvcl::math::vec4f jesus_center_position,
                kmuvcl::math::vec4f alucy_center_position,
                kmuvcl::math::vec4f statue_center_position)
  {
      float d = 4.0f;
      float distance = sqrt(pow(center_position(0)- libert_center_position(0),2 ) + pow(center_position(1) - libert_center_position(1), 2) + pow(center_position(2) - libert_center_position(2), 2));
      if(distance < d){
        libert_ratio += 0.1f;
        return 1;
      }


      distance = sqrt(pow(center_position(0)- jesus_center_position(0),2 ) + pow(center_position(1) - jesus_center_position(1), 2) + pow(center_position(2) - jesus_center_position(2), 2));
      if(distance < d){
        libert_ratio += 0.1f;
        return 1;
      }


      distance = sqrt(pow(center_position(0)- alucy_center_position(0),2 ) + pow(center_position(1) - alucy_center_position(1), 2) + pow(center_position(2) - alucy_center_position(2), 2));
      if(distance < d){
        libert_ratio += 0.1f;
        return 1;
      }

      distance = sqrt(pow(center_position(0)- statue_center_position(0),2 ) + pow(center_position(1) - statue_center_position(1), 2) + pow(center_position(2) - statue_center_position(2), 2));
      if(distance < d){
        libert_ratio += 0.1f;
        return 1;
      }

      return 0;
  }
  void draw(kmuvcl::math::mat4x4f mat_Model, kmuvcl::math::mat4x4f mat_Proj, kmuvcl::math::mat4x4f mat_View_inv)
  {
    GLfloat vertices[] = {
      // front
      -1, 1, 1,   1, 1, 1,   1,-1, 1,  -1,-1, 1,
      // back
      1, 1, -1,  -1, 1, -1,  -1,-1, -1,   1,-1, -1,
      // top
      -1, 1, -1,   1, 1, -1,   1, 1, 1,  -1, 1, 1,
      // bottom
      -1,-1, 1,   1,-1, 1,   1,-1, -1,  -1,-1, -1,
      // right
      1, 1, 1,   1, 1, -1,   1,-1, -1,   1,-1, 1,
      // left
      -1, 1, -1,  -1, 1, 1,  -1,-1, 1,  -1,-1, -1,
    };
    GLfloat normals[] = {
      0,0,1,   0,0,1,    0,0,1,    0,0,1,
      0,0,-1,  0,0,-1,   0,0,-1,   0,0,-1,
      0,1,0,   0,1,0,    0,1,0,    0,1,0,
      0,-1,0,  0,-1,0,   0,-1,0,  0,-1,0,
      1,0,0,  1,0,0,     1,0,0,   1,0,0,
      -1,0,0, -1,0,0,    -1,0,0,  -1,0,0,
    };
    GLfloat texcoords[] = {
      // front
      0,1,  1,1,  1,0,  0,0,
      // back
      0,1,  1,1,  1,0,  0,0,
      // top
      0,1,  1,1,  1,0,  0,0,
      // bottom
      0,1,  1,1,  1,0,  0,0,
      // right
      0,1,  1,1,  1,0,  0,0,
      // left
      0,1,  1,1,  1,0,  0,0,
    };

    GLushort indices[] = {
      //front
      0, 3, 2,   2, 1, 0,
      //back
      4, 7, 6,   6, 5, 4,
      // top
      8,11,10,  10, 9, 8,
      // bottom
      12,15,14,  14,13,12,
      //right
      16,19,18,  18,17,16,
      //left
      20,23,22,  22,21,20,
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

      kmuvcl::math::vec4f ambient  = kmuvcl::math::vec4f(1.0f, 0.5f, 0.5f, 1.0f);
      kmuvcl::math::vec4f diffuse  = kmuvcl::math::vec4f(1.0f, 0.5f, 0.5f, 1.0f);
      kmuvcl::math::vec4f specular = kmuvcl::math::vec4f(1.0f, 0.5f, 0.5f, 1.0f);
      float shininess              = 40.0f;

      glUniform4fv(loc_u_material_ambient, 1, ambient);
      glUniform4fv(loc_u_material_diffuse, 1, diffuse);
      glUniform4fv(loc_u_material_specular, 1, specular);
      glUniform1f(loc_u_material_shininess, shininess);


      //glVertexAttribPointer(loc_a_texcoord, 2, GL_FLOAT, GL_FALSE, 0, texcoords);
      glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, GL_FALSE, 0, vertices);
      glVertexAttribPointer(loc_a_normal, 3, GL_FLOAT, GL_FALSE, 0, normals);

      glEnableVertexAttribArray(loc_a_vertex);
      glEnableVertexAttribArray(loc_a_normal);
      //glEnableVertexAttribArray(loc_a_texcoord);

      glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLushort), GL_UNSIGNED_SHORT, indices);

      glDisableVertexAttribArray(loc_a_vertex);
      glDisableVertexAttribArray(loc_a_normal);
      //glDisableVertexAttribArray(loc_a_texcoord);
  }
};
