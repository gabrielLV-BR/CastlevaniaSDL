add_library(
  managers
  InputManager.cpp
  TextureManager.cpp
  AnimationManager.cpp
)

target_link_libraries(
  ${PROJECT_NAME} managers
)