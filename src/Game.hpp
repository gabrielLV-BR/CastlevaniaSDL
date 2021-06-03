#ifndef GAME_H

#define GAME_H

#include <SDL2/SDL.h>
#include "managers/InputManager.hpp"
#include "utilities/TileMap.hpp"

extern InputManager Input;

namespace GameFunctions {
  extern int GetWidth();
  extern int GetHeight();
  extern TileMap* GetTileMap();
}

class Game
{
private:
  bool _isRunning;
  SDL_Window* _window;
public:
  Game(const char* title, int width, int height, bool isFullscreen);
  ~Game();

  void Initialize(const char*, int, int, bool);

  void Update(float delta);
  void Render();
  void Clean();

  static SDL_Renderer* _renderer;

  bool inline Running() { return _isRunning;}
};

#endif