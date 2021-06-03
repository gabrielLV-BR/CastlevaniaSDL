add_library(
  utilities
  Functions.cpp
  TileMap.cpp
  Vector.cpp
  JSONLoader.cpp
)

target_link_libraries(
  ${PROJECT_NAME} utilities
)