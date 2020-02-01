// hello_world.cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "vec.hpp"
#include "mat.hpp"
#include "operator.hpp"
#include "transform.hpp"

void init();
void mydisplay();


GLuint create_shader_from_file(const std::string& filename, GLuint shader_type);

GLuint program; // 쉐이더 프로그램 객체의 레퍼런스 값
GLint  loc_a_position;
GLint  loc_a_color;
GLint  loc_u_Model;

std::vector<std::vector<kmuvcl::math::vec4f>> pos; // 각 단계의 점들을 모아놓은 배열
std::vector<kmuvcl::math::vec4f> pos_1; // 0단계의 점들을 모아놓은 배열
std::vector<kmuvcl::math::vec4f> pos_2; // 1단계의 점들을 모아놓은 배열
std::vector<kmuvcl::math::vec4f> pos_3; // 2단계의 점들을 모아놓은 배열
std::vector<kmuvcl::math::vec4f> pos_4; // 3단계의 점들을 모아놓은 배열
std::vector<kmuvcl::math::vec4f> pos_5; // 4단계의 점들을 모아놓은 배열

kmuvcl::math::mat4x4f color; // shader로 넘겨줄 color 배열
float offset; // offset 할 비율을 결정하는 변수
int max, min, ratio, is_draw; // offset할 최대최소 개수, 각 단계에서 그리는 사각형개수의 비율

int minmaxrand(){
  if(min!=0 && max!=0)
    return rand() % max + min;
  else
    return 0;
}  //최대 최소 사이의 수를 결정하는 랜덤 함수
/////메뉴 설정하기
void processOffsetMenu(int option){
  switch(option){
    case 1 :
      offset = 0.9f;
      break;
    case 2 :
      offset = 0.7f;
      break;
    case 3 :
      offset = 0.5f;
      break;
  }
  glutPostRedisplay();
  is_draw = 1;
}
void processNumMenu(int option){
  switch(option){
    case 1 :
      min = 1;
      max = 5;
      std::cout<< min<< max<<std::endl;
      break;
    case 2 :
      min = 5;
      max = 15;
      break;
    case 3 :
      min = 15;
      max = 30;
      break;
  }
  glutPostRedisplay();
  is_draw = 1;
}
void processRatioMenu(int option){
  switch(option){
    case 1:
      ratio = 2;
      break;
    case 2:
      ratio = 3;
      break;
    case 3:
      ratio = 5;
      break;
  }
  glutPostRedisplay();
  is_draw = 1;
}
void processColorMenu(int option){
  switch(option){
    case 1:
      color[0] = color[4] = color[8] = color[12] = 1.0f;
      color[1] = color[5] = color[9] = color[13] = 0.0f;
      color[2] = color[6] = color[10] = color[14] = 0.0f;
      break;
    case 2:
    color[0] = color[4] = color[8] = color[12] = 0.0f;
    color[1] = color[5] = color[9] = color[13] = 1.0f;
    color[2] = color[6] = color[10] = color[14] = 0.0f;
      break;
    case 3:
    color[0] = color[4] = color[8] = color[12] = 0.0f;
    color[1] = color[5] = color[9] = color[13] = 0.0f;
    color[2] = color[6] = color[10] = color[14] = 1.0f;
      break;
  }
  glutPostRedisplay();
  is_draw = 1;
}
void createGLUTMenus(){
  int mainmenu, colormenu, offsetmenu, nummenu, ratiomenu;

  colormenu = glutCreateMenu(processColorMenu);
  glutAddMenuEntry("Red", 1);
  glutAddMenuEntry("Green", 2);
  glutAddMenuEntry("Blue", 3);

  offsetmenu = glutCreateMenu(processOffsetMenu);
  glutAddMenuEntry("0.9", 1);
  glutAddMenuEntry("0.7", 2);
  glutAddMenuEntry("0.5", 3);

  nummenu = glutCreateMenu(processNumMenu);
  glutAddMenuEntry("1/5", 1);
  glutAddMenuEntry("5/15", 2);
  glutAddMenuEntry("15/30", 3);

  ratiomenu = glutCreateMenu(processRatioMenu);
  glutAddMenuEntry("2", 1);
  glutAddMenuEntry("3", 2);
  glutAddMenuEntry("5", 3);

  mainmenu = glutCreateMenu(processOffsetMenu);
  glutAddSubMenu("Color Menu", colormenu);
  glutAddSubMenu("Offset Menu",offsetmenu);
  glutAddSubMenu("Num Menu",nummenu);
  glutAddSubMenu("Ratio Menu",ratiomenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
////////////////
int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Hello_world");

  init();
  glutDisplayFunc(mydisplay);
  createGLUTMenus();
  glutMainLoop();

  return 0;
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
  // 각 단계의 힐베르트 곡선위의 점 구하기
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

  pos_1.push_back(kmuvcl::math::vec4f(0.5f, -0.5f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(0.5f, 0.0f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(0.5f, 0.5f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(0.0f, 0.5f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(-0.5f, 0.5f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(-0.5f, 0.0f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(-0.5f, -0.5f, 0.0f, 1.0f));

  for(int i=0; i<pos_1.size(); i++){
    kmuvcl::math::vec4f tmp = kmuvcl::math::scale(0.5f, 0.5f, 0.5f) * pos_1[i];
    pos_2.push_back(kmuvcl::math::translate(0.5f, 0.5f, 0.0f) * tmp);
    pos_2.push_back(kmuvcl::math::translate(-0.5f, 0.5f, 0.0f) *tmp);
    pos_2.push_back(kmuvcl::math::translate(-0.5f, -0.5f, 0.0f) * kmuvcl::math::rotate(-90.0f, 0.0f, 0.0f, 1.0f) *tmp);
    pos_2.push_back(kmuvcl::math::translate(0.5f, -0.5f, 0.0f)* kmuvcl::math::rotate(90.0f, 0.0f, 0.0f, 1.0f) *tmp);
  }
  for(int i=0; i<pos_2.size(); i++){
    kmuvcl::math::vec4f tmp = kmuvcl::math::scale(0.5f, 0.5f, 0.5f) * pos_2[i];
    pos_3.push_back(kmuvcl::math::translate(0.5f, 0.5f, 0.0f) *tmp);
    pos_3.push_back(kmuvcl::math::translate(-0.5f, 0.5f, 0.0f) *tmp);
    pos_3.push_back(kmuvcl::math::translate(-0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(-90.0f, 0.0f, 0.0f, 1.0f) *tmp);
    pos_3.push_back(kmuvcl::math::translate(0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(90.0f, 0.0f, 0.0f, 1.0f) *tmp);
  }
  for(int i=0; i<pos_3.size(); i++){
    kmuvcl::math::vec4f tmp = kmuvcl::math::scale(0.5f, 0.5f, 0.5f) * pos_3[i];
    pos_4.push_back(kmuvcl::math::translate(0.5f, 0.5f, 0.0f) *tmp);
    pos_4.push_back(kmuvcl::math::translate(-0.5f, 0.5f, 0.0f) *tmp);
    pos_4.push_back(kmuvcl::math::translate(-0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(-90.0f, 0.0f, 0.0f, 1.0f) *tmp);
    pos_4.push_back(kmuvcl::math::translate(0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(90.0f, 0.0f, 0.0f, 1.0f) *tmp);
  }
  for(int i=0; i<pos_4.size(); i++){
    kmuvcl::math::vec4f tmp = kmuvcl::math::scale(0.5f, 0.5f, 0.5f) * pos_4[i];
    pos_5.push_back(kmuvcl::math::translate(0.5f, 0.5f, 0.0f) *tmp);
    pos_5.push_back(kmuvcl::math::translate(-0.5f, 0.5f, 0.0f) *tmp);
    pos_5.push_back(kmuvcl::math::translate(-0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(-90.0f, 0.0f, 0.0f, 1.0f) *tmp);
    pos_5.push_back(kmuvcl::math::translate(0.5f, -0.5f, 0.0f)*kmuvcl::math::rotate(90.0f, 0.0f, 0.0f, 1.0f) *tmp);
  }

  pos.push_back(pos_1);
  pos.push_back(pos_2);
  pos.push_back(pos_3);
  pos.push_back(pos_4);
  pos.push_back(pos_5);

  offset = 0.9f;
  min = 5; max = 15;
  ratio = 2;
  is_draw = 1;
  processColorMenu(1);
}

void draw_a_rectangle(float size, float x, float y){
  kmuvcl::math::mat4x4f model_matrix;
  kmuvcl::math::mat4x4f S, T;

  float position[] = {
    0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 1.0f,
  };

  float r_color = rand()%100 * 0.01f;

  kmuvcl::math::mat4x4f color_scale = kmuvcl::math::scale(r_color, r_color, r_color); // color 배열에 random 으로 scale 해주기 위한 변수


  T = kmuvcl::math::translate(x, y, 0.0f);
  S = kmuvcl::math::scale(size, size, 1.0f);

  model_matrix = T*S;

  glUniformMatrix4fv(loc_u_Model, 1, GL_FALSE, model_matrix);
  glVertexAttribPointer(loc_a_position, 4, GL_FLOAT, GL_FALSE, 0, position);
  glVertexAttribPointer(loc_a_color, 4, GL_FLOAT, GL_FALSE, 0, color_scale * color);

  glEnableVertexAttribArray(loc_a_position);
  glEnableVertexAttribArray(loc_a_color);

  glDrawArrays(GL_QUADS, 0, 4);

  glDisableVertexAttribArray(loc_a_position);
  glDisableVertexAttribArray(loc_a_color);


}

void draw_a_rectangle_group(){
  int level_rect_num = 2;

  for(int level = 0; level< 5; level++){    // 각 단계
    int point_num = 7 * pow(4,level); // 각 단계에서 존재하는 점의 개수

    for(int i = 0; i< level_rect_num; i++){  // 단계에서 선택할 사각형 개수 *=ratio
      float size = pow(0.5f, level);   //각 단계에서 제일 큰 사각형의 사이즈
      int randnum = rand();
      float x = pos[level][randnum%point_num](0); //힐베르트 곡선위의 한점
      float y = pos[level][randnum%point_num](1); //힐베르트 곡선위의 한점
      int num_rects = minmaxrand();   // 오프셋 할 개수 (min,max) 사이
      for(int i=0; i<num_rects; i++){  // 오프셋 할 개수
        draw_a_rectangle(size, x, y);  /// 기본 사각형 및 오프셋된 사각형 그리기
        size *=offset;  // size 의 offset
      }
    }
    level_rect_num *= ratio;
  }

}
void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  srand(time(NULL));
  glUseProgram(program);


  draw_a_rectangle_group();

  glUseProgram(0);

  glutSwapBuffers();
}
