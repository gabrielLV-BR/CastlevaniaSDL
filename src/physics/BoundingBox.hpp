#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <SDL2/SDL.h>
#include "../utilities/Vector.hpp"

struct BoundingBox
{
  BoundingBox(float x, float y, float w, float h);
  BoundingBox(const Vector2D& position, float w, float h);
  BoundingBox(const SDL_Rect& rect);

  /*
  left-x/top-y ----------- right-x
      |                  |
      |                  |
      |                  |
      |                  |
      |                  |
      |                  |
      |                  |
      |                  |
    bottom-y --------bottom-y + right-x

      ---------top----------
      |                   |
      |                   |
      |                   |
      |                   |
    left                right
      |                   |
      |                   |
      |                   |
      |                   |
      -------bottom---------
*/

  float left, right, top, bottom;
};

#endif