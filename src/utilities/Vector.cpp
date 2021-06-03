#include "Vector.hpp"
#include "../utilities/Functions.hpp"

Vector2D Vector2D::Copy()
{
  return {x, y};
}

Vector2D::Vector2D()
  :x(0), y(0)
{}

Vector2D::Vector2D(float _x, float _y)
  :x(_x), y(_y)
{}

Vector2D::~Vector2D()
{}

void Vector2D::Add(const Vector2D& vec)
{
  this->x += vec.x;
  this->y += vec.y;
}

void Vector2D::Add(float scalar)
{
  this->x += scalar;
  this->y += scalar;
}

void Vector2D::Subtract(const Vector2D& vec)
{
  this->x -= vec.x;
  this->y -= vec.y;
}

void Vector2D::Subtract(float scalar)
{
  this->x -= scalar;
  this->y -= scalar;
}

void Vector2D::Multiply(float scalar)
{
  this->x *= scalar;
  this->y *= scalar;
}

void Vector2D::Divide(float scalar)
{
  this->x /= scalar;
  this->y /= scalar;
}

void Vector2D::Lerp(float goal, float delta)
{
  this->x = Functions::Lerp(this->x, goal, delta);
  this->y = Functions::Lerp(this->y, goal, delta);
}

void Vector2D::Lerp(const Vector2D& goal, float delta)
{
  this->x = Functions::Lerp(this->x, goal.x, delta);
  this->y = Functions::Lerp(this->y, goal.y, delta);
}


Vector2D Vector2D::operator+(const Vector2D vec) const
{
  return {this->x + vec.x, this->y + vec.y};
}

Vector2D Vector2D::operator-(const Vector2D vec) const
{
  return {this->x - vec.x, this->y - vec.y};
}

Vector2D Vector2D::operator*(float scalar) const
{
  return {this->x * scalar, this->y * scalar};
}

Vector2D Vector2D::operator/(float scalar) const
{
  return {this->x / scalar, this->y / scalar};
}

float Vector2D::GetMag() const
{
  return sqrt((x * x) + (y * y));
}

float Vector2D::Normalize()
{
  float mag = GetMag();
  if(mag != 0) this->Divide(mag);
  return mag;
}

void Vector2D::SetMag(float mag)
{
  if(mag != 0)
  {
    this->Normalize();
    this->Multiply(mag);
  }
}

float Vector2D::DotProduct(const Vector2D& vec) const
{
  return (x * vec.x) + (y * vec.y);
}

float Vector2D::GetAngleTo(const Vector2D& vec) const
{
  float dot = DotProduct(vec);

  float angle = acos(dot / (GetMag() / vec.GetMag())) * 180 / M_PI;
  return angle;
}

bool Vector2D::operator==(const Vector2D& vec) const
{
  return x == vec.x && y == vec.y;
}

bool Vector2D::operator!=(const Vector2D& vec) const
{
  return !((*this) == vec);
}

const Vector2D Vector2D::ZERO = Vector2D(0.0f, 0.0f);