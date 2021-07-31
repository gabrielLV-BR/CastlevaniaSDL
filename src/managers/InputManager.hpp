#ifndef INPUTMANAGER_H

#define INPUTMANAGER_H

#include "../Libs.h"
#include <unordered_map>
#include "../utilities/Vector.hpp"

class InputManager
{
public:
  static InputManager& Get();
  
  static void PollInput();
  static bool IsPressed(SDL_Keycode keycode);
  static bool ShouldQuit();
  static const Vector2D& GetMousePosition();

private:
  std::unordered_map<SDL_Keycode, bool> pressedKeys;
  bool shouldQuit;
  Vector2D mousePos;

  InputManager();
  ~InputManager();

  void IPollInput();
  bool IIsPressed(SDL_Keycode);
  const Vector2D& IGetMousePosition();
};

// class InputManager
// {
// private:
//   bool shouldQuit = false;
// public:
//   InputManager();
//   ~InputManager();

//   void PollInput();  
//   bool IsPressed(SDL_Keycode);
//   bool ShouldQuit();

//   std::map<SDL_Keycode, bool> pressedKeys;
//  };

#endif