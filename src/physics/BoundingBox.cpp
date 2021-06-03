#include "BoundingBox.hpp"

BoundingBox::BoundingBox(float x, float y, float w, float h)
  :left(x), right(x + w), top(y), bottom(y + h)
{}

BoundingBox::BoundingBox(const Vector2D& position, float w, float h)
  :left(position.x), right(position.x + w), top(position.y), bottom(position.y + h)
{}

BoundingBox::BoundingBox(const SDL_Rect& rect)
  :left(rect.x), right(rect.x + rect.w), top(rect.y), bottom(rect.y + rect.h)
{}