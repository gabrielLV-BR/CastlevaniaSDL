#ifndef JSONLOADER_H
#define JSONLOADER_H

#include <json/json.h>
#include <json/value.h>

namespace JSONLoader
{
  Json::Value Load(const char*);
}

#endif