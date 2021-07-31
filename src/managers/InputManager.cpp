#include "InputManager.hpp"
#include "../Libs.h"

InputManager::InputManager()
{
  pressedKeys[SDLK_s] = false;
  pressedKeys[SDLK_w] = false;
  pressedKeys[SDLK_a] = false;
  pressedKeys[SDLK_d] = false;
  pressedKeys[SDLK_SPACE] = false;
  shouldQuit = false;
}

InputManager::~InputManager()
{}

InputManager& InputManager::Get()
{
  static InputManager instance;
  return instance;
}

void InputManager::PollInput()
{
  Get().IPollInput();
}

const Vector2D& InputManager::GetMousePosition()
{
  return Get().IGetMousePosition();
}

bool InputManager::IsPressed(SDL_Keycode keycode)
{
  return Get().IIsPressed(keycode);
}

bool InputManager::ShouldQuit()
{
  return Get().shouldQuit;
}

void InputManager::IPollInput()
{
  SDL_Event event;
  
  while(SDL_PollEvent(&event))
  {

    SDL_Keycode code = event.key.keysym.sym;
    auto iterator = pressedKeys.find(code);

    if(event.type == SDL_QUIT) {
      shouldQuit = true;
    }

    if(event.type == SDL_MOUSEMOTION)
    {
      int newMouseX, newMouseY;
      SDL_GetMouseState(&newMouseX, &newMouseY);

      mousePos.x = (int) newMouseX;
      mousePos.y = (int) newMouseY;
      continue;
    }

    if(iterator == pressedKeys.end()) continue;

    pressedKeys[code] = event.type == SDL_KEYDOWN;
  }
}

const Vector2D& InputManager::IGetMousePosition()
{
  return mousePos;
}

bool InputManager::IIsPressed(SDL_Keycode code)
{
  auto iterator = pressedKeys.find(code);

  if(iterator == pressedKeys.end()) return false;

  return pressedKeys[code];
}