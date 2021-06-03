#include "../Game.hpp"
#include "./TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* path)
{
  SDL_Surface* surface = IMG_Load(path);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::_renderer, surface);

  SDL_FreeSurface(surface);

  return texture;
}

SDL_Surface* TextureManager::LoadSurface(const char* path)
{
  SDL_Surface* surface = IMG_Load(path);

  return surface;
}