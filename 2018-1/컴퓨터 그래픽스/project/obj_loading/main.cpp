// Defines the entry point for the console application.
//
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "Object.h"
#include "Shader.h"
#include "Camera.h"
#include "Bullet.h"
#include "SOIL.h"

#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"

void init();
void display();
void reshape(int, int);
void keyboard(unsigned char, int, int);
void special(int, int, int);

void idle();

GLuint program;

GLint  loc_a_vertex;
GLint  loc_a_normal;

GLint  loc_u_pvm_matrix;
GLint  loc_u_view_matrix;
GLint  loc_u_model_matrix;
GLint  loc_u_normal_matrix;

GLint  loc_u_light_vector;

GLint  loc_u_light_ambient;
GLint  loc_u_light_diffuse;
GLint  loc_u_light_specular;

GLint  loc_u_material_ambient;
GLint  loc_u_material_diffuse;
GLint  loc_u_material_specular;
GLint  loc_u_material_shininess;

GLint  loc_a_texcoord;
GLint  loc_u_texid;

GLuint texid_wall;
GLuint texid_floor;

kmuvcl::math::mat4x4f   mat_PVM;

kmuvcl::math::vec4f light_vector      = kmuvcl::math::vec4f(10.0f, 10.0f, 10.0f);
kmuvcl::math::vec4f light_ambient     = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);
kmuvcl::math::vec4f light_diffuse     = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);
kmuvcl::math::vec4f light_specular    = kmuvcl::math::vec4f(1.0f, 1.0f, 1.0f, 1.0f);

std::string g_filename;
Object      g_libert, g_jesus, g_alucy, g_statue, g_bar,
            g_desk, g_fan, g_sofa, g_tv, g_wall, g_floor;
Camera      g_camera;
float obj_select = 4;

std::chrono::time_point<std::chrono::system_clock> prev, curr;

std::vector<kmuvcl::math::mat4x4f> obj_mat_Model;
kmuvcl::math::vec4f libert_center_position;
kmuvcl::math::vec4f jesus_center_position;
kmuvcl::math::vec4f alucy_center_position;
kmuvcl::math::vec4f statue_center_position;
std::vector<Bullet> g_bullet;

void processObjMenu(int option){
  switch(option){
    case 0:
      obj_select = 0;
    break;

    case 1:
      obj_select = 1;
    break;

    case 2:
      obj_select = 2;
    break;

    case 3:
      obj_select = 3;
    break;

    case 4:
      obj_select = 4;
    break;
  }
}
void createGLUTMenus(){
  int obj_menu;
  obj_menu = glutCreateMenu(processObjMenu);
  glutAddMenuEntry("Libert", 0);
  glutAddMenuEntry("Jesus", 1);
  glutAddMenuEntry("Alucy", 2);
  glutAddMenuEntry("Statue", 3);
  glutAddMenuEntry("Camera", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 640);
  glutCreateWindow("Modeling & Navigating Your Studio");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  createGLUTMenus();
  glutSpecialFunc(special);
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
  g_desk.load_simple_obj("./data/desk_with_normals.obj");
  g_fan.load_simple_obj("./data/fan_with_normals.obj");
  g_sofa.load_simple_obj("./data/sofa_with_normals.obj");
  g_tv.load_simple_obj("./data/tv_with_normals.obj");

  g_libert.load_simple_obj("./data/LibertStatue.obj");
  g_jesus.load_simple_obj("./data/Jesus_Statue/Jesus_Statue.obj");
  g_jesus.load_simple_mtl("./data/Jesus_Statue/Jesus_Statue.mtl");
  g_alucy.load_simple_obj("./data/Alucy.obj");
  g_statue.load_simple_obj("./data/statue/statue.obj");
  g_bar.load_simple_obj("./data/barrier.obj");

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);    // for filled polygon rendering

  glEnable(GL_DEPTH_TEST);

  program = Shader::create_program("./shader/phong_vert.glsl", "./shader/phong_frag.glsl");

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

  prev = curr = std::chrono::system_clock::now();

  obj_mat_Model.push_back(kmuvcl::math::scale(1.0f, 1.0f, 1.0f));
  obj_mat_Model.push_back(kmuvcl::math::scale(1.0f, 1.0f, 1.0f));
  obj_mat_Model.push_back(kmuvcl::math::scale(1.0f, 1.0f, 1.0f));
  obj_mat_Model.push_back(kmuvcl::math::scale(1.0f, 1.0f, 1.0f));

  loc_u_texid      = glGetUniformLocation(program, "u_texid");
  loc_a_texcoord   = glGetAttribLocation(program, "a_texcoord");

  int width, height, channels;

  unsigned char* wall = SOIL_load_image("wall.jpg",&width, &height, &channels, SOIL_LOAD_RGB);

  glGenTextures(1, &texid_wall);

  glBindTexture(GL_TEXTURE_2D, texid_wall);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, wall);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);

  SOIL_free_image_data(wall);

  unsigned char* ground = SOIL_load_image("floor.jpg",&width, &height, &channels, SOIL_LOAD_RGB);

  glGenTextures(1, &texid_floor);

  glBindTexture(GL_TEXTURE_2D, texid_floor);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ground);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);

  SOIL_free_image_data(ground);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(program);

  kmuvcl::math::mat4x4f   mat_Proj, mat_View_inv, mat_Model;

  mat_View_inv = kmuvcl::math::lookAt(
		g_camera.position()(0), g_camera.position()(1), g_camera.position()(2),				// eye position
		g_camera.center_position()(0), g_camera.center_position()(1), g_camera.center_position()(2), // center position
		g_camera.up_direction()(0), g_camera.up_direction()(1), g_camera.up_direction()(2)			// up direction
		);

  mat_Proj = kmuvcl::math::perspective(g_camera.fovy(), 1.0f, 0.001f, 10000.0f);

  glUniform3fv(loc_u_light_vector, 1, light_vector);
  glUniform4fv(loc_u_light_ambient, 1, light_ambient);
  glUniform4fv(loc_u_light_diffuse, 1, light_diffuse);
  glUniform4fv(loc_u_light_specular, 1, light_specular);
  Shader::check_gl_error("glUniform4fv");

  mat_Model = obj_mat_Model[0] * kmuvcl::math::translate(-9.0f, 0.0f, -12.0f) * kmuvcl::math::scale(5.5f, 5.5f, 5.5f);
  libert_center_position =  mat_Model * kmuvcl::math::translate(0.0f, 1.0f, 0.0f) * kmuvcl::math::vec4f(0.0f, 0.0f, 0.0f, 1.0f);
  g_libert.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[1] * kmuvcl::math::translate(-9.0f, 0.0f, 12.0f) * kmuvcl::math::rotate(180.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(1.0f, 1.0f, 1.0f);
  jesus_center_position = mat_Model * kmuvcl::math::translate(0.0f, 1.0f, 0.0f) * kmuvcl::math::vec4f(0.0f, 0.0f, 0.0f, 1.0f);
  g_jesus.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[2] * kmuvcl::math::translate( 9.0f, 0.0f,  12.0f) * kmuvcl::math::rotate(270.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.005f, 0.005f, 0.005f);
  alucy_center_position = mat_Model * kmuvcl::math::translate(0.0f, 1.0f, 0.0f) * kmuvcl::math::vec4f(0.0f, 0.0f, 0.0f, 1.0f);
  g_alucy.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[3] * kmuvcl::math::translate( 9.0f, 0.0f, -12.0f) * kmuvcl::math::scale(1.0f, 1.0f, 1.0f);
  statue_center_position = mat_Model * kmuvcl::math::translate(0.0f, 1.0f, 0.0f) * kmuvcl::math::vec4f(0.0f, 0.0f, 0.0f, 1.0f);
  g_statue.draw2(mat_Model, mat_Proj, mat_View_inv);

  for(int i=0; i<g_bullet.size(); i++){
    mat_Model = kmuvcl::math::scale(0.1f, 0.1f, 0.1f);
    mat_Model = kmuvcl::math::translate(g_bullet[i].pos(0), g_bullet[i].pos(1), g_bullet[i].pos(2)) * mat_Model;
    mat_Model = kmuvcl::math::translate(g_bullet[i].front_dir(0) * g_bullet[i].ratio, g_bullet[i].front_dir(1) * g_bullet[i].ratio, g_bullet[i].front_dir(2) * g_bullet[i].ratio) * mat_Model;

    g_bullet[i].center_position = mat_Model * g_bullet[i].center_position;

    if(g_bullet[i].collision(libert_center_position, jesus_center_position,
                      alucy_center_position,statue_center_position))
      g_bullet.erase(g_bullet.begin() + i);

    g_bullet[i].draw(mat_Model, mat_Proj, mat_View_inv);

  }

  mat_Model = obj_mat_Model[2] * kmuvcl::math::translate( 9.0f, 0.0f,  9.6f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[3] * kmuvcl::math::translate( 9.0f, 0.0f, -9.6f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[1] * kmuvcl::math::translate(-9.0f, 0.0f,  9.6f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[0] * kmuvcl::math::translate(-9.0f, 0.0f, -9.6f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[2] * kmuvcl::math::translate( 6.6f, 0.0f,  12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[3] * kmuvcl::math::translate( 6.6f, 0.0f, -12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[1] * kmuvcl::math::translate(-6.6f, 0.0f,  12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[0] * kmuvcl::math::translate(-6.6f, 0.0f, -12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[2] * kmuvcl::math::translate( 11.6f, 0.0f,  12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[3] * kmuvcl::math::translate( 11.6f, 0.0f, -12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[1] * kmuvcl::math::translate(-11.6f, 0.0f,  12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = obj_mat_Model[0] * kmuvcl::math::translate(-11.6f, 0.0f, -12.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(0.4f, 0.4f, 0.4f);
  g_bar.draw2(mat_Model, mat_Proj, mat_View_inv);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texid_floor);
  glUniform1i(loc_u_texid, 0);
  mat_Model = kmuvcl::math::translate( 0.0f, 0.0f,  0.0f) * kmuvcl::math::rotate(360.0f, 0.0f, 90.0f, 0.0f) * kmuvcl::math::scale(80.0f, 0.02f, 80.0f);
  g_floor.draw3(mat_Model, mat_Proj, mat_View_inv);

  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, texid_wall);
  glUniform1i(loc_u_texid, 1);
  mat_Model = kmuvcl::math::translate( 0.0f, 2.0f, -18.0f) * kmuvcl::math::scale(80.0f, 20.0f, 0.6f);
  g_wall.draw3(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = kmuvcl::math::translate( 0.0f, 2.0f,  16.0f) * kmuvcl::math::scale(320.0f, 20.0f, 0.6f);
  g_wall.draw3(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = kmuvcl::math::translate(-16.0f, 2.0f,  16.0f) * kmuvcl::math::rotate(90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(320.0f, 20.0f, 0.6f);
  g_wall.draw3(mat_Model, mat_Proj, mat_View_inv);

  mat_Model = kmuvcl::math::translate( 16.0f, 2.0f,  0.0f) * kmuvcl::math::rotate(-90.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(160.0f, 20.0f, 0.6f);
  g_wall.draw3(mat_Model, mat_Proj, mat_View_inv);

  Shader::check_gl_error("draw");

	glUseProgram(0);

  glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
  // TODO: properly handle keyboard event
  switch(key){
    case 'A': case 'a':
      g_camera.rotate_left(1.0f);
    break;

    case 'D': case 'd':
      g_camera.rotate_right(1.0f);
    break;

    case 'W': case 'w':
      g_camera.rotate_up(1.0f);
    break;

    case 'S': case 's':
      g_camera.rotate_down(1.0f);
    break;

    case 'Q': case 'q':
      g_bullet.push_back(Bullet(kmuvcl::math::vec4f(g_camera.front_dir_(0), g_camera.front_dir_(1), g_camera.front_dir_(2), 1.0f), kmuvcl::math::vec3f(g_camera.position_(0), g_camera.position_(1), g_camera.position_(2)), 1.0f, kmuvcl::math::vec4f(0.0f, 0.0f, 0.0f, 1.0f)));
    break;

  }
	glutPostRedisplay();
}
int collision()
{
  float d = 6.8f;
  float distance = sqrt(pow(g_camera.position_(0)-libert_center_position(0),2) +
     pow(g_camera.position_(1)-libert_center_position(1),2) +
     pow(g_camera.position_(2)-libert_center_position(2),2)) ;

  if(distance < d)
    return 1;

  distance = sqrt(pow(g_camera.position_(0)-jesus_center_position(0),2) +pow(g_camera.position_(1)-jesus_center_position(1),2) +pow(g_camera.position_(2)-jesus_center_position(2),2)) ;

  if(distance < d)
    return 1;

  distance = sqrt(pow(g_camera.position_(0)-alucy_center_position(0),2) +pow(g_camera.position_(1)-alucy_center_position(1),2) +pow(g_camera.position_(2)-alucy_center_position(2),2)) ;

  if(distance < d)
    return 1;

  distance = sqrt(pow(g_camera.position_(0)-statue_center_position(0),2) +pow(g_camera.position_(1)-statue_center_position(1),2) +pow(g_camera.position_(2)-statue_center_position(2),2)) ;

  if(distance < d)
    return 1;
}
void special(int key, int x, int y)
{
  if(obj_select < 4){

    switch(key){
      case GLUT_KEY_LEFT:
        obj_mat_Model[obj_select] = obj_mat_Model[obj_select] * kmuvcl::math::translate(-0.1f, 0.0f, 0.0f);
        break;
      case GLUT_KEY_RIGHT:
        obj_mat_Model[obj_select] = obj_mat_Model[obj_select] * kmuvcl::math::translate(0.1f, 0.0f, 0.0f);
        break;
      case GLUT_KEY_DOWN:
        obj_mat_Model[obj_select] = obj_mat_Model[obj_select] * kmuvcl::math::translate(0.0f, 0.0f, 0.1f);
        break;
      case GLUT_KEY_UP:
        obj_mat_Model[obj_select] = obj_mat_Model[obj_select] * kmuvcl::math::translate(0.0f, 0.0f, -0.1f);
        break;
    }
  }
  else{
	// TODO: properly handle special keyboard event
    switch(key){
      case GLUT_KEY_LEFT:
        g_camera.move_left(0.1f);
        if(collision())
          g_camera.move_right(0.1f);
        break;
      case GLUT_KEY_RIGHT:
        g_camera.move_right(0.1f);
        if(collision())
          g_camera.move_left(0.1f);
        break;
      case GLUT_KEY_DOWN:
        g_camera.move_backward(0.1f);
        if(collision())
          g_camera.move_forward(0.1f);
        break;
      case GLUT_KEY_UP:
        g_camera.move_forward(0.1f);
        if(collision())
          g_camera.move_backward(0.1f);
        break;
    }
  }
	glutPostRedisplay();
}
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}

void idle()
{
  curr = std::chrono::system_clock::now();

  std::chrono::duration<float> elaped_seconds = (curr - prev);

  for(int i=0; i<g_bullet.size(); i++)
    g_bullet[i].ratio += 0.1f;

  prev = curr;

  glutPostRedisplay();
}
