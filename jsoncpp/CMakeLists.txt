add_library(
  jsoncpp
  jsoncpp.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  jsoncpp
)