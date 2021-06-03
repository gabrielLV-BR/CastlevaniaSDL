#ifndef GAMEOBJECT_H

#define GAMEOBJECT_H

#include "../Game.hpp"
#include "../utilities/Vector.hpp"
#include "../physics/BoundingBox.hpp"

class Entity
{
public:
  Vector2D position;
  Entity(float, float);

  virtual void Update(float) = 0;
  virtual void Render() = 0;
  virtual BoundingBox GetBoundingBox() = 0;
};

#endif