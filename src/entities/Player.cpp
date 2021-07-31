#include "../Game.hpp"
#include "Player.hpp"
#include "../managers/TextureManager.hpp"
#include "../physics/BoundingBox.hpp"
#include "../utilities/Functions.hpp"

#include <iostream>

const int size = 3;

void DrawDebugTile(const SDL_Rect& rect)
{
  auto tileMap = GameFunctions::GetTileMap();

  float realTile = tileMap->GetTileSize();

  int x = (rect.x + rect.w / 2) / realTile;
  int y = (rect.y + rect.h / 2) / realTile;

  int tile = tileMap->GetTileIDAt(Vector2D(x, y));
  std::cout << "Tile: " << tile << std::endl;

  SDL_Rect drawRect;
  drawRect.x = x * realTile;
  drawRect.y = y * realTile;
  drawRect.w = drawRect.h = realTile;

  SDL_SetRenderDrawColor(Game::_renderer, 0xff, 0x00, 0x00, 0xff);
  SDL_RenderDrawRect(Game::_renderer, &drawRect);
}

Player::Player(float x, float y, const char* path)
: Entity(x, y), velocity(0, 0), facingRight(true), isCrouched(false),
  canJump(false), animationManager("../../res/sprites/simon.json")
{
  texture = TextureManager::LoadTexture("../../res/sprites/simon.png");

  playerRects.UV = {0, 0, 16, 32};

  playerRects.position = {(int)x, (int)y, 16 * size, 32 * size};
}

const float friction = 60.0f;
const float speed = 30.0f;
const float gravity = 20.0f;
const float jumpForce = 300.0f;

void Player::Update(float delta)
{
  isGrounded = IsGrounded();

  float xAccel = InputManager::IsPressed(SDLK_d) - InputManager::IsPressed(SDLK_a); 

  velocity.y += gravity;

  // SEM IF PORRAAAA

  // Se isGrounded for true, o ! flippa pra não que é zero e zera o vel.y
  velocity.y *= (!isGrounded);
  // Se espaço estiver pressionado e estiver grounded, esse && retorna 1, e multiplicado
  // pelo jumpForce dá certo.
  velocity.y -= jumpForce * (InputManager::IsPressed(SDLK_SPACE) && isGrounded);

  const float velMargin = 0.1f;
  // IF, PORRAAA
  if(xAccel == 0.0f)
  {
    // Velocity.x == 0
    velocity.x = Functions::Lerp(velocity.x, xAccel * friction, delta * 10.0f);

    animationManager.SetTag("Idle");

    if(abs(velocity.x) < velMargin) velocity.x = 0.0f;
  }else
  {
    animationManager.SetTag("Walking");

    // Velocity.x != 0

    velocity.x = Functions::Lerp(velocity.x, xAccel * speed, delta * 10.0f);

    facingRight = velocity.x > 0.0f;
  }

  if(!isGrounded || isCrouched)
  {
    animationManager.SetTag("Duck");
  }

  Move(delta);
  animationManager.Animate(delta);
}


void Player::Move(float delta)
{
  Vector2D moveVel = velocity;

  moveVel.Multiply(delta);
  position.Add(moveVel);

  Vector2D response = CalculateCollisionResponse();

  position.Add(response);
}

Vector2D Player::CalculateCollisionResponse() const
{
  auto tileMap = GameFunctions::GetTileMap();

  using namespace GameFunctions;

  BoundingBox boundingBox(position, playerRects.position.w, playerRects.position.h);
  BoundingBox window(0.0f, 0.0f, GetWidth(), GetHeight());

  bool left = boundingBox.left >= window.left;
  bool right = boundingBox.right <= window.right;
  bool top = boundingBox.top >= window.top;
  bool bottom = boundingBox.bottom <= window.bottom;
  
  if(left && right && bottom && top)
  {
    return {0.0f, 0.0f};
  }

  Vector2D difference(0.0f, 0.0f);

  //

  //

  if (!left) difference.x = window.left - boundingBox.left;
  else if (!right) difference.x = window.right - boundingBox.right;

  if (!bottom) difference.y = window.bottom - boundingBox.bottom;
  else if (!top) difference.y = window.top - boundingBox.top;

  return difference;
}

void Player::Render()
{
  playerRects.UV.x = playerRects.UV.w * animationManager.GetFrame();
  playerRects.position.x = position.x;
  playerRects.position.y = position.y;

  SDL_RendererFlip flags = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL & facingRight);

  SDL_RenderCopyEx(Game::_renderer, texture, &playerRects.UV, &playerRects.position, 0.0, NULL, flags);
  DrawDebugTile(playerRects.position);
}

bool Player::IsGrounded() const 
{
  using namespace GameFunctions;
  return (position.y + playerRects.position.h) >= GetHeight() - 1;
}

BoundingBox Player::GetBoundingBox()
{
  BoundingBox boundingBox = {
    (float)playerRects.position.x,
    (float)playerRects.position.y,
    (float)playerRects.position.w,
    (float)(playerRects.position.h / (isCrouched + 1)),
  };

  return boundingBox;
}