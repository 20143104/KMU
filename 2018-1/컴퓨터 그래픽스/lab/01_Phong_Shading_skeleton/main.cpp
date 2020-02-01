// Defines the entry point for the console application.
//
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "Teapot.h"
#include "Shader.h"

#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"

void init();
void display();
void reshape(int, int);
void idle();

GLuint program;

GLint  loc_a_vertex;
GLint  loc_a_normal;

GLint  loc_u_pvm_matrix;
GLint  loc_u_view_matrix;
GLint  loc_u_model_matrix;
GLint  loc_u_normal_matrix;

GLint  loc_u_light_vector;   // 빛의 위치

GLint  loc_u_light_ambient;
GLint  loc_u_light_diffuse;
GLint  loc_u_light_specular;

GLint  loc_u_material_ambient;
GLint  loc_u_material_diffuse;
GLint  loc_u_material_specular;
GLint  loc_u_material_shininess; // 표면이 얼마나 반짝이는가

float model_scale = 5.0f;
float model_angle = 0.0f;

kmuvcl::math::mat4x4f mat_PVM;
kmuvcl::math::mat3x3f mat_Normal;

kmuvcl::math::vec3f light_vector      = kmuvcl::math::vec3f(10.0f, 10.0f, 10.0f);
kmuvcl::math::vec4f light_ambient     = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);
kmuvcl::math::vec4f light_diffuse     = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);
kmuvcl::math::vec4f light_specular    = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);

kmuvcl::math::vec4f material_ambient  = kmuvcl::math::vec4f(0.464f, 0.393f, 0.094f, 1.0f);
kmuvcl::math::vec4f material_diffuse  = kmuvcl::math::vec4f(0.464f, 0.393f, 0.094f, 1.0f);
kmuvcl::math::vec4f material_specular = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);
float     material_shininess= 50.0f;

Teapot*   tespot;

std::clock_t curr, prev;

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 640);
  glutCreateWindow("Modeling & Navigating Your Studio");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);

  if (glewInit() != GLEW_OK)
  {
    std::cerr << "failed to initialize glew" << std::endl;
    return -1;
  }

  init();

  glutMainLoop();

  return 0;
}

void init()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  glFrontFace(GL_CCW);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);    // for wireframe rendering 표면이 채워진-

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  glEnable(GL_DEPTH_TEST);

  // TODO: Edit shader codes
  program = Shader::create_program("./shader/phong_vert.glsl", "./shader/phong_frag.glsl");

  // TODO: Get locations of variables in shader program
  loc_u_pvm_matrix         = glGetUniformLocation(program, "u_pvm_matrix");
  loc_u_view_matrix        = glGetUniformLocation(program, "u_view_matrix");
  loc_u_model_matrix       = glGetUniformLocation(program, "u_model_matrix");
  loc_u_normal_matrix      = glGetUniformLocation(program, "u_normal_matrix");

  loc_u_light_vector       = glGetUniformLocation(program, "u_light_vector");
  loc_u_light_ambient      = glGetUniformLocation(program, "u_light_ambient");
  loc_u_light_diffuse      = glGetUniformLocation(program, "u_light_diffuse");
  loc_u_light_specular     = glGetUniformLocation(program, "u_light_specular");

  loc_u_material_ambient   = glGetUniformLocation(program, "u_material_ambient");
  loc_u_material_diffuse   = glGetUniformLocation(program, "u_material_diffuse");
  loc_u_material_specular  = glGetUniformLocation(program, "u_material_specular");
  loc_u_material_shininess = glGetUniformLocation(program, "u_material_shininess");

  loc_a_vertex             = glGetAttribLocation(program, "a_vertex");
  loc_a_normal             = glGetAttribLocation(program, "a_normal");


  tespot = new Teapot();

  curr = std::clock();
  prev = curr;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(program);

  // Camera setting
  kmuvcl::math::mat4x4f   mat_Proj, mat_View_inv, mat_Model;

  // camera intrinsic param
  mat_Proj = kmuvcl::math::perspective(60.0f, 1.0f, 0.001f, 10000.0f);

  // camera extrinsic param
  mat_View_inv = kmuvcl::math::lookAt(
    0.0f, 0.0f, 3.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f);

  mat_Model = kmuvcl::math::scale(model_scale, model_scale, model_scale);
  mat_Model = kmuvcl::math::rotate(model_angle*0.7f, 0.0f, 0.0f, 1.0f) * mat_Model;
  mat_Model = kmuvcl::math::rotate(model_angle,      0.0f, 1.0f, 0.0f) * mat_Model;
  mat_Model = kmuvcl::math::rotate(model_angle*0.5f, 1.0f, 0.0f, 0.0f) * mat_Model;

  mat_PVM = mat_Proj*mat_View_inv*mat_Model;

  // TODO: normal matrix, view matrix

  mat_Normal(0,0) = mat_Model(0,0);
  mat_Normal(0,1) = mat_Model(0,1);  // 모델의 윗부분만 가져와서 노말매트릭스로
  mat_Normal(0,2) = mat_Model(0,2);
  mat_Normal(1,0) = mat_Model(1,0);
  mat_Normal(1,1) = mat_Model(1,1);
  mat_Normal(1,2) = mat_Model(1,2);
  mat_Normal(2,0) = mat_Model(2,0);
  mat_Normal(2,1) = mat_Model(2,1);
  mat_Normal(2,2) = mat_Model(2,2);

  kmuvcl::math::mat4x4f mat_View = kmuvcl::math::inverse(mat_View_inv);

  // TODO: Set uniform varibles in shader program
  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);
  glUniformMatrix4fv(loc_u_view_matrix, 1, false, mat_View);
  glUniformMatrix4fv(loc_u_model_matrix, 1, false, mat_Model);
  glUniformMatrix3fv(loc_u_normal_matrix, 1, false, mat_Normal);

  glUniformMatrix3fv(loc_u_light_vector, 1, false, light_vector);
  glUniformMatrix4fv(loc_u_light_ambient, 1, false, light_ambient);
  glUniformMatrix4fv(loc_u_light_diffuse, 1, false, light_diffuse);
  glUniformMatrix4fv(loc_u_light_specular, 1, false, light_specular);

  glUniformMatrix4fv(loc_u_material_ambient, 1, false, material_ambient);
  glUniformMatrix4fv(loc_u_material_diffuse, 1, false, material_diffuse);
  glUniformMatrix4fv(loc_u_material_specular, 1, false, material_specular);
  glUniform1f(loc_u_material_shininess, material_shininess);


  // Draw teapot
  tespot->draw(loc_a_vertex, loc_a_normal);

  glUseProgram(0);
  Shader::check_gl_error("draw");

  glutSwapBuffers();
}

void reshape(int width, int height)
{
  glViewport(0, 0, width, height);
}

void idle()
{
  curr = std::clock();

  float clock_diff = (float)(prev-curr);
  float elaped_seconds = clock_diff / CLOCKS_PER_SEC;

  model_angle += 100.0f * elaped_seconds;

  prev = curr;

  glutPostRedisplay();
}
