# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabriellv/dev/c/castlevaniaSDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabriellv/dev/c/castlevaniaSDL/build

# Include any dependencies generated for this target.
include src/managers/CMakeFiles/managers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/managers/CMakeFiles/managers.dir/compiler_depend.make

# Include the progress variables for this target.
include src/managers/CMakeFiles/managers.dir/progress.make

# Include the compile flags for this target's objects.
include src/managers/CMakeFiles/managers.dir/flags.make

src/managers/CMakeFiles/managers.dir/InputManager.cpp.o: src/managers/CMakeFiles/managers.dir/flags.make
src/managers/CMakeFiles/managers.dir/InputManager.cpp.o: ../src/managers/InputManager.cpp
src/managers/CMakeFiles/managers.dir/InputManager.cpp.o: src/managers/CMakeFiles/managers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriellv/dev/c/castlevaniaSDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/managers/CMakeFiles/managers.dir/InputManager.cpp.o"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/managers/CMakeFiles/managers.dir/InputManager.cpp.o -MF CMakeFiles/managers.dir/InputManager.cpp.o.d -o CMakeFiles/managers.dir/InputManager.cpp.o -c /home/gabriellv/dev/c/castlevaniaSDL/src/managers/InputManager.cpp

src/managers/CMakeFiles/managers.dir/InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/managers.dir/InputManager.cpp.i"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriellv/dev/c/castlevaniaSDL/src/managers/InputManager.cpp > CMakeFiles/managers.dir/InputManager.cpp.i

src/managers/CMakeFiles/managers.dir/InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/managers.dir/InputManager.cpp.s"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriellv/dev/c/castlevaniaSDL/src/managers/InputManager.cpp -o CMakeFiles/managers.dir/InputManager.cpp.s

src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o: src/managers/CMakeFiles/managers.dir/flags.make
src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o: ../src/managers/TextureManager.cpp
src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o: src/managers/CMakeFiles/managers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriellv/dev/c/castlevaniaSDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o -MF CMakeFiles/managers.dir/TextureManager.cpp.o.d -o CMakeFiles/managers.dir/TextureManager.cpp.o -c /home/gabriellv/dev/c/castlevaniaSDL/src/managers/TextureManager.cpp

src/managers/CMakeFiles/managers.dir/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/managers.dir/TextureManager.cpp.i"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriellv/dev/c/castlevaniaSDL/src/managers/TextureManager.cpp > CMakeFiles/managers.dir/TextureManager.cpp.i

src/managers/CMakeFiles/managers.dir/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/managers.dir/TextureManager.cpp.s"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriellv/dev/c/castlevaniaSDL/src/managers/TextureManager.cpp -o CMakeFiles/managers.dir/TextureManager.cpp.s

src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o: src/managers/CMakeFiles/managers.dir/flags.make
src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o: ../src/managers/AnimationManager.cpp
src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o: src/managers/CMakeFiles/managers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriellv/dev/c/castlevaniaSDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o -MF CMakeFiles/managers.dir/AnimationManager.cpp.o.d -o CMakeFiles/managers.dir/AnimationManager.cpp.o -c /home/gabriellv/dev/c/castlevaniaSDL/src/managers/AnimationManager.cpp

src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/managers.dir/AnimationManager.cpp.i"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriellv/dev/c/castlevaniaSDL/src/managers/AnimationManager.cpp > CMakeFiles/managers.dir/AnimationManager.cpp.i

src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/managers.dir/AnimationManager.cpp.s"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriellv/dev/c/castlevaniaSDL/src/managers/AnimationManager.cpp -o CMakeFiles/managers.dir/AnimationManager.cpp.s

# Object files for target managers
managers_OBJECTS = \
"CMakeFiles/managers.dir/InputManager.cpp.o" \
"CMakeFiles/managers.dir/TextureManager.cpp.o" \
"CMakeFiles/managers.dir/AnimationManager.cpp.o"

# External object files for target managers
managers_EXTERNAL_OBJECTS =

src/managers/libmanagers.a: src/managers/CMakeFiles/managers.dir/InputManager.cpp.o
src/managers/libmanagers.a: src/managers/CMakeFiles/managers.dir/TextureManager.cpp.o
src/managers/libmanagers.a: src/managers/CMakeFiles/managers.dir/AnimationManager.cpp.o
src/managers/libmanagers.a: src/managers/CMakeFiles/managers.dir/build.make
src/managers/libmanagers.a: src/managers/CMakeFiles/managers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabriellv/dev/c/castlevaniaSDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libmanagers.a"
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && $(CMAKE_COMMAND) -P CMakeFiles/managers.dir/cmake_clean_target.cmake
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/managers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/managers/CMakeFiles/managers.dir/build: src/managers/libmanagers.a
.PHONY : src/managers/CMakeFiles/managers.dir/build

src/managers/CMakeFiles/managers.dir/clean:
	cd /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers && $(CMAKE_COMMAND) -P CMakeFiles/managers.dir/cmake_clean.cmake
.PHONY : src/managers/CMakeFiles/managers.dir/clean

src/managers/CMakeFiles/managers.dir/depend:
	cd /home/gabriellv/dev/c/castlevaniaSDL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabriellv/dev/c/castlevaniaSDL /home/gabriellv/dev/c/castlevaniaSDL/src/managers /home/gabriellv/dev/c/castlevaniaSDL/build /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers /home/gabriellv/dev/c/castlevaniaSDL/build/src/managers/CMakeFiles/managers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/managers/CMakeFiles/managers.dir/depend
