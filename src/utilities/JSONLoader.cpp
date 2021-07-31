#include "JSONLoader.hpp"
#include <fstream>
#include "../Libs.h"

Json::Value JSONLoader::Load(const char* path)
{
  std::ifstream file(path);
  Json::Value json;
  Json::Reader reader;

  reader.parse(file, json);
  return json;
}