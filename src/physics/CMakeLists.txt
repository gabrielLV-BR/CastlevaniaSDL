add_library(
  physics
  BoundingBox.cpp
)

target_link_libraries(
  ${PROJECT_NAME} physics
)