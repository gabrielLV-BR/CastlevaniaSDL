# Add the main.cpp file to the project
add_executable(
  ${PROJECT_NAME}
  main.cpp 
  Game.cpp 
)

add_subdirectory(entities)
add_subdirectory(managers)
add_subdirectory(physics)
add_subdirectory(utilities)

# deus é BOM parceiro

set(CMAKE_MODULE_PATH "/usr/share/cmake/Modules/")

# aqui nóis procuremo a bibrosteca SDL2 e guardemo o caminho dela na variavir sdl2 (minusculo!!!)


find_library(sdl2 SDL2)
find_library(sdl2_image SDL2_image)

# chequemo pra ver se deu bom, o cmake é meio tantan

if(NOT sdl2)
  message(FATAL_ERROR "Could not find SDL2")
endif()

if(NOT sdl2_image)
  message(FATAL_ERROR "Could not find SDL2_image")
endif()

target_link_libraries(${PROJECT_NAME} ${sdl2} ${sdl2_image})