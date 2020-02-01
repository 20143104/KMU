#include "Camera.h"
#include "transform.hpp"

const kmuvcl::math::vec3f Camera::center_position() const
{

  kmuvcl::math::vec3f center_position(position_(0) + front_dir_(0),
                 position_(1) + front_dir_(1),
                 position_(2) + front_dir_(2));
  return center_position;
}

// TODO: fill up the following functions properly
void Camera::move_forward(float delta)
{
  position_(0) += front_dir_(0) * delta;
  position_(1) += front_dir_(1) * delta;
  position_(2) += front_dir_(2) * delta;
}

void Camera::move_backward(float delta)
{
  position_(0) += front_dir_(0) * -delta;
  position_(1) += front_dir_(1) * -delta;
  position_(2) += front_dir_(2) * -delta;
}

void Camera::move_left(float delta)
{
  position_(0) += right_dir_(0) * -delta;
  position_(1) += right_dir_(1) * -delta;
  position_(2) += right_dir_(2) * -delta;
}

void Camera::move_right(float delta)
{
  position_(0) += right_dir_(0) * delta;
  position_(1) += right_dir_(1) * delta;
  position_(2) += right_dir_(2) * delta;
}

void Camera::rotate_left(float delta)
{

  kmuvcl::math::vec4f temp_front_position(front_dir_(0), front_dir_(1), front_dir_(2), 1.0f);
  kmuvcl::math::vec4f temp_right_position(right_dir_(0), right_dir_(1), right_dir_(2), 1.0f);

  kmuvcl::math::mat4x4f rotate = kmuvcl::math::rotate(delta,up_dir_(0),up_dir_(1),up_dir_(2));

  kmuvcl::math::vec4f transformedvector = rotate * temp_front_position;

  front_dir_(0) = transformedvector(0);
  front_dir_(1) = transformedvector(1);
  front_dir_(2) = transformedvector(2);

  transformedvector = rotate * temp_right_position;

  right_dir_(0) = transformedvector(0);
  right_dir_(1) = transformedvector(1);
  right_dir_(2) = transformedvector(2);

}

void Camera::rotate_right(float delta)
{
  kmuvcl::math::vec4f temp_front_position(front_dir_(0), front_dir_(1), front_dir_(2), 1.0f);
  kmuvcl::math::vec4f temp_right_position(right_dir_(0), right_dir_(1), right_dir_(2), 1.0f);

  kmuvcl::math::mat4x4f rotate = kmuvcl::math::rotate(-delta,up_dir_(0),up_dir_(1),up_dir_(2));

  kmuvcl::math::vec4f transformedvector = rotate * temp_front_position;

  front_dir_(0) = transformedvector(0);
  front_dir_(1) = transformedvector(1);
  front_dir_(2) = transformedvector(2);

  transformedvector = rotate * temp_right_position;

  right_dir_(0) = transformedvector(0);
  right_dir_(1) = transformedvector(1);
  right_dir_(2) = transformedvector(2);
}
