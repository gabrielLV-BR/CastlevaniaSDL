#include "Game.hpp"
#include "managers/InputManager.hpp"

#define SDL_MAIN_HANDLED

int main()
{
  Game game("Game", 800, 640, false);

  const int desiredFPS = 60;
  const int frameDelay = 1000/desiredFPS;

  Uint32 frameStart;
  int frameTime;

  float ticks, lastTime, delta;

  while(!Input.ShouldQuit())
  {
    ticks = SDL_GetTicks();
    delta = (ticks - lastTime) / 100;

    frameStart = SDL_GetTicks();

    InputManager::PollInput();
    game.Update(delta);
    game.Render();
  
    frameTime = SDL_GetTicks() -  frameStart;

    lastTime = SDL_GetTicks();

    if(frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }
  return 0;
}