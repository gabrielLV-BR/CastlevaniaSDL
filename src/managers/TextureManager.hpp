#ifndef TEXTUREMANAGER_H

#define TEXTUREMANAGER_H

#include "../Game.hpp"
#include "../Libs.h"

class TextureManager 
{
private:
  TextureManager();
  ~TextureManager();
public:
  static SDL_Texture* LoadTexture(const char*);
  // Depois de utilizar, use SDL_FreeSurface()!
  static SDL_Surface* LoadSurface(const char*);
};

#endif