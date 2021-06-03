#ifndef TILEMAP_H

#define TILEMAP_H

#include "../Game.hpp"
#include <vector>

struct TileMapData
{
  int tileSize, tileMapRows, tileMapCols;
};

class TileMap 
{
private:

  SDL_Rect srcRectangle, destRectangle;
  SDL_Rect UV, position;
  SDL_Texture* tileSheet;

  unsigned char* map;

  TileMapData tileMapData;

  float resize;
  int rows, cols;

public:
  TileMap(const char*, const char*, int, float);
  ~TileMap();

  void LoadTileMap(const char*, const char*);
  void Render();
  int GetTileAt(const Vector2D&) const;
  int GetTileIDAt(const Vector2D&) const;
  int GetTileSize();
  float GetResizeFactor();
};

#endif