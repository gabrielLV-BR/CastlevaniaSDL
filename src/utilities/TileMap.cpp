#include "../Game.hpp"
#include "../managers/TextureManager.hpp"
#include "JSONLoader.hpp"
#include <fstream>

#include "TileMap.hpp"

int lvl1[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

TileMap::TileMap(const char* imagePath, const char* jsonPath, int tileSize, float resize)
{
  resize = 1.0f;

  rows = 1;
  cols = 1;
  tileMapData.tileMapCols = 1;
  tileMapData.tileMapRows = 1;
  tileMapData.tileSize = tileSize;

  LoadTileMap(imagePath, jsonPath);
}

TileMap::~TileMap()
{}

void TileMap::LoadTileMap(const char* imagePath, const char* jsonPath)
{
  using namespace GameFunctions;

  Json::Value json = JSONLoader::Load(jsonPath);

  int newRows = json["numRows"].asInt();
  int newCols = json["numCols"].asInt();

  if(rows != newRows || cols != newCols)
  {
    rows = newRows;
    cols = newCols;
    map = new unsigned char[cols * rows];
  }

  int i = 0;
  for(Json::Value& id : json["map"])
  {
    map[i++] = id.asInt();
  }

  SDL_Surface* surface = TextureManager::LoadSurface(imagePath);

  tileSheet = SDL_CreateTextureFromSurface(Game::_renderer, surface);
  tileMapData.tileMapCols = surface->w / tileMapData.tileSize;
  tileMapData.tileMapRows = surface->h / tileMapData.tileSize;

  SDL_FreeSurface(surface);

  UV = {0, 0, tileMapData.tileSize, tileMapData.tileSize};
  position = UV;
  position.h = position.w = GetHeight() / (rows - 1);
}

void TileMap::Render()
{
  int i = 0;
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      int id = map[i++];

      UV.x = id * 16;

      position.x = c * position.w;
      position.y = r * position.h;

      SDL_RenderCopy(Game::_renderer, tileSheet, &UV, &position);
    }
  }
}

float TileMap::GetResizeFactor()
{
  return resize;
}

int TileMap::GetTileSize()
{
  return position.w;
}

int TileMap::GetTileAt(const Vector2D& vec) const
{
  int x = vec.x / tileMapData.tileSize;
  int y = vec.y / tileMapData.tileSize;
  return x + y * cols;
}

int TileMap::GetTileIDAt(const Vector2D& vec) const
{
  int pos = GetTileAt(vec);
  return map[pos];
}