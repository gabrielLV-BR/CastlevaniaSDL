#include "Functions.hpp"

float Functions::Lerp(float current, float goal, float delta=0.16f)
{
  const float margin = 0.2f;

  if (abs((int)(goal - current)) <= margin) return goal;
  if(current < goal)  return current += delta;
  return current -= delta;
}