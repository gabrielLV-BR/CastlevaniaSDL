#include "JSONLoader.hpp"
#include <fstream>

Json::Value JSONLoader::Load(const char* path)
{
  std::ifstream file(path);
  Json::Value json;
  Json::Reader reader;

  reader.parse(file, json);
  return json;
}