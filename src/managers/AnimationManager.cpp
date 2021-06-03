#include "AnimationManager.hpp"
#include "../utilities/JSONLoader.hpp"

const std::string INVALID = "INVALID";

AnimationFrame::AnimationFrame(int x, int y, int w, int h, int dur)
: duration(dur)
{
  sourceFrame = new SDL_Rect();
  (*sourceFrame) = {x, y, w, h};
}

AnimationCycle::AnimationCycle(int f, int t, const char r)
: from(f), to(t), repeatMode(r)
{}

AnimationCycle::~AnimationCycle(){}

AnimationManager::AnimationManager(const char* spriteSheetConfigPath)
  : frame(0), currentTag("")
{
  Json::Value json = JSONLoader::Load(spriteSheetConfigPath);

  frames.reserve(json["frames"].size());
  cycles.reserve(json["meta"]["frameTags"].size());

  int counter = 0;

  for(auto k : json["frames"])
  {
    const int x = k["frame"]["x"].asInt();
    const int y = k["frame"]["y"].asInt();
    const int w = k["frame"]["w"].asInt();
    const int h = k["frame"]["h"].asInt();
    const int duration = k["duration"].asInt();

    frames.push_back(new AnimationFrame(x, y, w, h, duration));
  }

  for(auto k : json["meta"]["frameTags"])
  {
    const char* name = k["name"].asCString(); 
    const int from = k["from"].asInt();
    const int to = k["to"].asInt();
    const char repeatMode = k["direction"].asCString()[0];
    
    cycles[name] = new AnimationCycle(from, to, repeatMode);
  } 
}

AnimationManager::~AnimationManager(){}

void AnimationManager::Animate(float delta)
{
  if(currentTag == INVALID) return;
  time += floor(delta * 100.0f);
  
  const auto cycle = cycles[currentTag];
  const int minFrame = cycle->from;
  const int maxFrame = cycle->to;
  const char dir = cycle->repeatMode;

  if(time > frames[frame]->duration)
  {
    time = 0.0f;
    switch(dir)
    { 
      // Forward
      case 'f':
        if(frame < cycle->to) frame++;
        break;
      // Repeat
      case 'r':
        if(frame > cycle->to) frame = cycle->from;
        else frame++;
        break;
      // Ping-Pong
      case 'p':
        static int accum = 1;

        frame += accum;

        if(frame >= cycle->to)
        {
          frame = cycle->to;
          accum = -1;
        }else if(frame <= cycle->from)
        {
          frame = cycle->from;
          accum = 1;
        }
        break;
    }
  }
}


void AnimationManager::SetTag(std::string tag)
{
  if(cycles.find(tag) != cycles.end() && currentTag != tag)
  {
    frame = cycles[tag]->from;
    this->currentTag = tag;
  }else if (currentTag != tag)
  {
    currentTag = INVALID;
  }
}

int AnimationManager::GetFrame()
{
  return frame;
}