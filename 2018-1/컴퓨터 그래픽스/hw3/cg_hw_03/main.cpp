// Defines the entry point for the console application.
//
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <fstream>

#include "Object.h"
#include "Camera.h"
#include "Shader.h"

#include "transform.hpp"

void init();
void display();
void reshape(int, int);
void idle();
void keyboard(unsigned char, int, int);
void special(int, int, int);

GLuint		program;

GLint			loc_a_vertex;
GLint			loc_u_pvm_matrix;

kmuvcl::math::mat4x4f mat_PVM;

Object		g_desk, g_fan, g_sofa, g_tv;  // furniture
Camera		g_camera;											// viewer (you)

float fanangle = 0.0f;

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
  g_desk.load_simple_obj("./data/desk.obj");
  g_fan.load_simple_obj("./data/fan.obj");
  g_sofa.load_simple_obj("./data/sofa.obj");
  g_tv.load_simple_obj("./data/tv.obj");

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    // for wireframe rendering

	program = Shader::create_program("./shader/simple.vert", "./shader/simple.frag");

	loc_u_pvm_matrix	= glGetUniformLocation(program, "u_pvm_matrix");

	loc_a_vertex			= glGetAttribLocation(program, "a_vertex");
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(program);

	// Camera setting
	kmuvcl::math::mat4x4f   mat_Proj, mat_View, mat_Model;

	// camera extrinsic param
	mat_View = kmuvcl::math::lookAt(
		g_camera.position()(0), g_camera.position()(1), g_camera.position()(2),				// eye position
		g_camera.center_position()(0), g_camera.center_position()(1), g_camera.center_position()(2), // center position
		g_camera.up_direction()(0), g_camera.up_direction()(1), g_camera.up_direction()(2)			// up direction
		);
	// camera intrinsic param
	mat_Proj = kmuvcl::math::perspective(g_camera.fovy(), 1.0f, 0.001f, 10000.0f);


	// TODO: draw furniture by properly transforming each object

  mat_Model = kmuvcl::math::translate(-5.0f, 0.0f, 0.0f) * kmuvcl::math::scale(1.5f, 1.5f, 1.5f);
  mat_PVM = mat_Proj*mat_View*mat_Model;
  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);

	g_desk.draw(loc_a_vertex);

  mat_Model = kmuvcl::math::mat4x4f(1.0f);
  mat_Model = kmuvcl::math::translate(0.0f, 5.0f, 0.0f) * kmuvcl::math::rotate(fanangle , 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(1.5f, 1.5f, 1.5f);
  mat_PVM = mat_Proj*mat_View*mat_Model;
  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);

	g_fan.draw(loc_a_vertex);

  mat_Model = kmuvcl::math::mat4x4f(1.0f);
  mat_Model = kmuvcl::math::translate(0.0f, 0.0f, 5.0f) * kmuvcl::math::rotate(180.0f, 0.0f, 1.0f, 0.0f) * kmuvcl::math::scale(1.5f, 1.5f, 1.5f);
  mat_PVM = mat_Proj*mat_View*mat_Model;
  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);

	g_sofa.draw(loc_a_vertex);

  mat_Model = kmuvcl::math::mat4x4f(1.0f);
  mat_Model = kmuvcl::math::translate(0.0f, 0.0f, -5.0f) * kmuvcl::math::scale(2.0f, 2.0f, 2.0f);
  mat_PVM = mat_Proj*mat_View*mat_Model;
  glUniformMatrix4fv(loc_u_pvm_matrix, 1, false, mat_PVM);

  g_tv.draw(loc_a_vertex);

	glUseProgram(0);
	Shader::check_gl_error("draw");

  glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
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
  }
	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	// TODO: properly handle special keyboard event
  switch(key){
    case GLUT_KEY_LEFT:
      g_camera.move_left(0.1f);
    break;
    case GLUT_KEY_RIGHT:
      g_camera.move_right(0.1f);
    break;
    case GLUT_KEY_DOWN:
      g_camera.move_backward(0.1f);
    break;
    case GLUT_KEY_UP:
      g_camera.move_forward(0.1f);
    break;
  }
	glutPostRedisplay();
}

void idle()
{
  // TODO: update your variables in idle time
  fanangle += 0.3f;
  glutPostRedisplay();
}
