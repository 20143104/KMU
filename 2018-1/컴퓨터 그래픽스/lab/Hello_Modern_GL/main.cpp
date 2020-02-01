// hello_world.cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include "operator.hpp"
#include "transform.hpp"
#include "vec.hpp"
#include "mat.hpp"



void init();
void mydisplay();
void myidle();
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type);

GLuint program; // 쉐이더 프로그램 객체의 레퍼런스 값
GLint  loc_a_position;
GLint  loc_a_color;
GLint  loc_u_Model;
float  dx = 0.0f, dy = 0.0f;

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Hello FreeGLUT");

  init();
  glutDisplayFunc(mydisplay);
  glutIdleFunc(myidle);
  glutMainLoop();
  return 0;
}
void myidle(){
  dx += 0.1f;
  dy += 0.1f;

  if(dx > 1)
    dx = 0.0f;
  if(dy > 1)
    dy = 0.0f;

  glutPostRedisplay();

  //mydisplay(); 내가 내스스로 다시그리는게 아니라 os가 요청했을 때 다시 그려야됨
  //나 다시그려야 되는데 요청하면 os가 그때 시간을 update할수있는
}

// GLSL 파일을 읽어서 컴파일한 후 쉐이더 객체를 생성하는 함수
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type)
{
  GLuint shader = 0;
  shader = glCreateShader(shader_type);
  std::ifstream shader_file(filename.c_str());
  std::string shader_string;
  shader_string.assign(
    (std::istreambuf_iterator<char>(shader_file)),
    std::istreambuf_iterator<char>());

  const GLchar* shader_src = shader_string.c_str();

  glShaderSource(shader, 1, (const GLchar**)&shader_src, NULL);
  glCompileShader(shader);

  return shader;
}


void init()
{
  glewInit();

  // 정점 쉐이더 객체를 파일로부터 생성
  GLuint vertex_shader
    = create_shader_from_file("./shader/vertex.glsl", GL_VERTEX_SHADER);

  // 프래그먼트 쉐이더 객체를 파일로부터 생성
  GLuint fragment_shader
    = create_shader_from_file("./shader/fragment.glsl", GL_FRAGMENT_SHADER);

  // 쉐이더 프로그램 생성 및 컴파일
  program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  loc_a_position = glGetAttribLocation(program, "a_position");
  loc_a_color    = glGetAttribLocation(program, "a_color");
  loc_u_Model    = glGetUniformLocation(program, "u_Model");
  //gpu 상에서 요이름으로 만들었던 위치를 알려달라

  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void mydisplay() // 매 프레임 마다 불리는 함수
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /*
  float position[] = {
    0.0f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 1.0f,
    0.0f, 0.5f, 0.0f, 1.0f,
  };*/

  float color[] = {
    1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 1.0f,
  }; // 이 데이터 들은 메인메모리에 있는 것

  kmuvcl::math::mat4x4f model_matrix;
  kmuvcl::math::mat4x4f position = kmuvcl::math::scale(0.5f,0.5f,0.5f);

  model_matrix = kmuvcl::math::translate(dx, dy, 0.0f);
  /*
  float model_matrix[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.3f, -0.1f, 0.0f, 1.0f, // 세로방향으로 해주어야함
  };*/
  glUseProgram(program); // 내가 이런 shader프로그램을 쓸거야

  glUniformMatrix4fv(loc_u_Model, 1, GL_FALSE, model_matrix);
  //위치 count 전치 유뮤 모델매트리스
  // 단순한 위치만 알려주는 데 16개의 점을 복사해 갈 것인가 (함수이름으로)
  glVertexAttribPointer(loc_a_position, 4, GL_FLOAT, GL_FALSE, 0, position); // gpu에 데이터를 쓸건데 위치가 loc_a_position 이라는 곳에 position을 쏠거야

  glVertexAttribPointer(loc_a_color, 4, GL_FLOAT, GL_FALSE, 0, color);

  glEnableVertexAttribArray(loc_a_color);
  glEnableVertexAttribArray(loc_a_position);

  glDrawArrays(GL_QUADS, 0, 4 /* 정점개수 */);

  glDisableVertexAttribArray(loc_a_color);
  glDisableVertexAttribArray(loc_a_position);

  glUseProgram(0); // shader프로그램을 내리겠다.

  glutSwapBuffers();
}
