#include <iostream>
#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"
#include <cmath>
#include <vector>

int main()
{
  kmuvcl::math::mat4x4f mat_Translate;
  kmuvcl::math::mat4x4f mat_Rotate;
  kmuvcl::math::mat4x4f mat_Scale;
  kmuvcl::math::mat4x4f mat_LookAt;
  kmuvcl::math::mat4x4f mat_Ortho;
  kmuvcl::math::mat4x4f mat_Frustum;
  kmuvcl::math::mat4x4f mat_Perspective;

  std::vector<std::vector<kmuvcl::math::vec4f>> pos;
  std::vector<kmuvcl::math::vec4f> pos_1;
  std::vector<kmuvcl::math::vec4f> pos_2;
  std::vector<kmuvcl::math::vec4f> pos_3;
  std::vector<kmuvcl::math::vec4f> pos_4;
  std::vector<kmuvcl::math::vec4f> pos_5;

  pos_1.push_back(kmuvcl::math::vec4f(0.5f, 0.0f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(0.0f, 0.5f, 0.0f, 1.0f));
  pos_1.push_back(kmuvcl::math::vec4f(-0.5f, 0.0f, 0.0f, 1.0f));

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

  for(int i=0; i<pos[1].size() ; i++){
	std::cout<<pos[1][i] << std::endl;
	}

	std::cout<<float(pow(0.5f,1))<<std::endl;
  /*
  mat_Translate = kmuvcl::math::translate(1.0f, -1.0f, 2.0f);
  std::cout << "Translation matrix" << std::endl;
  std::cout << mat_Translate << std::endl;

  mat_Rotate = kmuvcl::math::rotate(90.0f, 1.0f, 2.0f, -1.0f);
  std::cout << "Rotation matrix" << std::endl;
  std::cout << mat_Rotate << std::endl;
  //std::cout << sin(90*3.1416/180);
  mat_Scale = kmuvcl::math::scale(2.0f, 1.0f, 1.5f);
  std::cout << "Scaling matrix" << std::endl;
  std::cout << mat_Scale << std::endl;

  mat_LookAt = kmuvcl::math::lookAt(0.0f, 0.0f, -5.0f,
                                    0.0f, 0.0f, 0.0f,
                                    0.0f, 1.0f, 0.0f);
  std::cout << "View matrix with lookAt()" << std::endl;
  std::cout << mat_LookAt << std::endl;

  mat_Ortho = kmuvcl::math::ortho(1.0f, -1.0f,
                                  1.0f, -1.0f,
                                  1.0f, -1.0f);
  std::cout << "Projection matrix with ortho()" << std::endl;
  std::cout << mat_Ortho << std::endl;

  mat_Frustum = kmuvcl::math::frustum(-0.1f, 0.1f,
                                      -0.1f, 0.1f,
                                       0.1f, 1000.0f);
  std::cout << "Projection matrix with frusutm()" << std::endl;
  std::cout << mat_Frustum << std::endl;

  mat_Perspective = kmuvcl::math::perspective(60.0f, 1.0f, 0.001f, 10000.0f);
  std::cout << "Projection matrix with perspective()" << std::endl;
  std::cout << mat_Perspective << std::endl;

  */
  return  0;
}
