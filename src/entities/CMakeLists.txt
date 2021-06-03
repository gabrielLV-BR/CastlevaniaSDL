add_library(
  entities
  Entity.cpp
  Player.cpp
)

target_link_libraries(
  ${PROJECT_NAME} entities
)