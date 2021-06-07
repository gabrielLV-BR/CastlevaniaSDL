add_library(
    dependencies
    jsoncpp/jsoncpp.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	dependencies
	SDL2/lib/x64/SDL2
	SDL2/lib/x64/SDL2main
	SDL2/lib/x64/SDL2_image
)