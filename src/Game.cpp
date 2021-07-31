#include "Libs.h"

#include "Game.hpp"
#include "entities/Player.hpp"
#include "utilities/TileMap.hpp"

Player* player;
TileMap* map;
SDL_Renderer* Game::_renderer = nullptr;

int width, height;

Game::Game(const char* title, int _width, int _height, bool isFullscreen)
{
  width  = _width;
  height = _height;

  int flags = isFullscreen & SDL_WINDOW_FULLSCREEN;

  // if(SDL_Init(SDL_INIT_EVERYTHING)) std::cout << "[ERROR] SDL2 was not initialized.\n";

  _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
  _renderer = SDL_CreateRenderer(_window, -1, 0);

  SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xff);

  // if(!_window) std::cout << "[ERROR] Could not create window.\n";
  // if(!_renderer) std::cout << "[ERROR] Could not create renderer.\n";

  //
  player = new Player(20, 20, "../../res/sprites/simon.png");
  map = new TileMap("../../res/tilemaps/level1.png", "../../res/tilemaps/level1.json", 16, 2.0f);
  //

  _isRunning = true;
}

Game::~Game()
{
  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
  // std::cout << "Goodbye...\n";
}

void Game::Update(float delta)
{
  player->Update(delta);
}

void Game::Render()
{
  SDL_RenderClear(_renderer);

  map->Render();
  player->Render();
 
  SDL_RenderPresent(_renderer);
}

int GameFunctions::GetWidth()
{
  return width;
}

int GameFunctions::GetHeight()
{
  return height;
}

TileMap* GameFunctions::GetTileMap()
{
  return map;
}