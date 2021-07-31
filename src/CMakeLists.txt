# Add the main.cpp file to the project
add_executable(
  ${PROJECT_NAME}
  WIN32
  main.cpp 
  Game.cpp 
)

add_subdirectory(dependencies)

add_subdirectory(entities)
add_subdirectory(managers)
add_subdirectory(physics)
add_subdirectory(utilities)

if(NOT WIN32)
  set(CMAKE_MODULE_PATH "/usr/share/cmake/Modules/")

  find_library(sdl2 SDL2)
  find_library(sdl2_image SDL2_image)
  
  if(NOT sdl2)
    message(FATAL_ERROR "Could not find SDL2")
  endif()
  
  if(NOT sdl2_image)
    message(FATAL_ERROR "Could not find SDL2_image")
  endif()
  
  target_link_libraries(${PROJECT_NAME} ${sdl2} ${sdl2_image})
endif()

