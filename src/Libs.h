#ifndef SDL_H

#include "dependencies/jsoncpp/json/json.h"

#if defined _WIN64 || defined _WIN32

#include "dependencies/SDL2/include/SDL.h"
#include "dependencies/SDL2/include/SDLmain.h"
#include "dependencies/SDL2/include/SDL_image.h"

#endif

#if __unix__

#include <SDL2/SDL.h>
#include <SDL2/SDLmain.h>
#include <SDL2/SDL_image.h>

#endif

#endif
