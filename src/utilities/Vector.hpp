#ifndef VECTOR_H

#define VECTOR_H

#include <math.h>

class Vector2D
{
public:
  float x, y;
  Vector2D();
  Vector2D(float, float);
  ~Vector2D();

  // Faz com função mesmo

  Vector2D Copy();

  void Add(const Vector2D& vec);
  void Add(float scalar);
  void Subtract(const Vector2D& vec);
  void Subtract(float scalar);
  void Multiply(float scalar);
  void Divide(float scalar);

  void Lerp(float goal, float delta);
  void Lerp(const Vector2D& goal, float delta);

  float GetMag() const;
  float Normalize();
  void SetMag(float);

  float GetAngleTo(const Vector2D&) const;

  float DotProduct(const Vector2D&) const;

  Vector2D operator+(const Vector2D) const;
  Vector2D operator-(const Vector2D) const;
  Vector2D operator*(float) const;
  Vector2D operator/(float) const;
  bool operator==(const Vector2D&) const;
  bool operator!=(const Vector2D&) const;

  static const Vector2D ZERO;

};

#endif