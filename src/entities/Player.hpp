#ifndef PLAYER_H

#define PLAYER_H

#include "Entity.hpp"
#include "../managers/AnimationManager.hpp"

enum PlayerState {IDLE, MOVING, ONAIR, ATTACKING};

struct Rects {
  SDL_Rect UV, position;
};

class Player: public Entity
{
private:
  AnimationManager animationManager;
  SDL_Texture* texture;
  Rects playerRects;

  Vector2D velocity, acceleration;

  bool facingRight, canJump, isGrounded;
  bool isCrouched;
public:
  Player(float, float, const char*);
  ~Player();

  Vector2D CalculateCollisionResponse() const;
  bool IsGrounded() const;

  void Update(float delta);
  void Move(float delta);
  BoundingBox GetBoundingBox();
  void Render();
};
#endif