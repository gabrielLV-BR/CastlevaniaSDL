#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "../Libs.h"
#include <unordered_map>
#include <string>
#include <vector>

struct AnimationFrame
{
  AnimationFrame();
  AnimationFrame(int, int, int, int, int);
  ~AnimationFrame();

  SDL_Rect* sourceFrame;
  int duration;
};

struct AnimationCycle
{
  AnimationCycle();
  AnimationCycle(int, int, char);
  ~AnimationCycle();

  int from, to;
  char repeatMode;
};

class AnimationManager
{
private:
  std::unordered_map<std::string, AnimationCycle*> cycles;
  std::vector<AnimationFrame*> frames;
  std::string currentTag;
  unsigned int frame;
  float time;

public:
  AnimationManager(const char*);
  ~AnimationManager();

  void Animate(float); // ou Update()
  int GetFrame();
  void SetTag(std::string);
};

#endif