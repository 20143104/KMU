#include <GL/glut.h>

void mydisplay();
void init();

float vertices[] = {
  0.5f, 0.5f, -0.5f,       -0.5f, 0.5f, -0.5f,     -0.5f,-0.5f,-0.5f,
  0.5f, 0.5f, -0.5f,       -0.5f, -0.5f, -0.5f,    0.5f, -0.5f, -0.5f,
};

float small_vertices[] = {
  0.25f, 0.25f, -0.25f,       -0.25f, 0.25f, -0.25f,     -0.25f,-0.25f,-0.25f,
  0.25f, 0.25f, -0.25f,       -0.25f, -0.25f, -0.25f,    0.25f, -0.25f, -0.25f
};

float small_colors[] = {
  0.0f, 1.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 1.0f,
  1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 0.0f,
};

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("simple");


  init();
  glutDisplayFunc(mydisplay);
  glutMainLoop();

  return 0;

}

void init()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0,
          -1.0, 1.0,
          -1.0, 1.0);


}
void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //매번 클리어 칼라로 화면을 색칠하겠다

  //green rectangle(vertex 6개 줫으면 색도 6번 주는게 일반적)
  //glColor3f(0.0f, 1.0f, 0.0f);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3, GL_FLOAT, 0, small_colors);
  glVertexPointer(3, GL_FLOAT, 0, small_vertices);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);


  //red rectangle
  glColor3f(1.0f, 0.0f, 0.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableClientState(GL_VERTEX_ARRAY);



  glFlush();

}
