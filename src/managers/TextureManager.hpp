#ifndef TEXTUREMANAGER_H

#define TEXTUREMANAGER_H

#include "../Game.hpp"
#include <SDL2/SDL.h>

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