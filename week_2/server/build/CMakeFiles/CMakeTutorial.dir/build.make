# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sf_linux/cplusclass1399/week_2/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_linux/cplusclass1399/week_2/server/build

# Include any dependencies generated for this target.
include CMakeFiles/CMakeTutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CMakeTutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CMakeTutorial.dir/flags.make

CMakeFiles/CMakeTutorial.dir/src/main.cpp.o: CMakeFiles/CMakeTutorial.dir/flags.make
CMakeFiles/CMakeTutorial.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_linux/cplusclass1399/week_2/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CMakeTutorial.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CMakeTutorial.dir/src/main.cpp.o -c /media/sf_linux/cplusclass1399/week_2/server/src/main.cpp

CMakeFiles/CMakeTutorial.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CMakeTutorial.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_linux/cplusclass1399/week_2/server/src/main.cpp > CMakeFiles/CMakeTutorial.dir/src/main.cpp.i

CMakeFiles/CMakeTutorial.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CMakeTutorial.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_linux/cplusclass1399/week_2/server/src/main.cpp -o CMakeFiles/CMakeTutorial.dir/src/main.cpp.s

CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.requires

CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.provides: CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CMakeTutorial.dir/build.make CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.provides

CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.provides.build: CMakeFiles/CMakeTutorial.dir/src/main.cpp.o


# Object files for target CMakeTutorial
CMakeTutorial_OBJECTS = \
"CMakeFiles/CMakeTutorial.dir/src/main.cpp.o"

# External object files for target CMakeTutorial
CMakeTutorial_EXTERNAL_OBJECTS =

CMakeTutorial: CMakeFiles/CMakeTutorial.dir/src/main.cpp.o
CMakeTutorial: CMakeFiles/CMakeTutorial.dir/build.make
CMakeTutorial: CMakeFiles/CMakeTutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_linux/cplusclass1399/week_2/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CMakeTutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CMakeTutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CMakeTutorial.dir/build: CMakeTutorial

.PHONY : CMakeFiles/CMakeTutorial.dir/build

CMakeFiles/CMakeTutorial.dir/requires: CMakeFiles/CMakeTutorial.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/CMakeTutorial.dir/requires

CMakeFiles/CMakeTutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CMakeTutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CMakeTutorial.dir/clean

CMakeFiles/CMakeTutorial.dir/depend:
	cd /media/sf_linux/cplusclass1399/week_2/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_linux/cplusclass1399/week_2/server /media/sf_linux/cplusclass1399/week_2/server /media/sf_linux/cplusclass1399/week_2/server/build /media/sf_linux/cplusclass1399/week_2/server/build /media/sf_linux/cplusclass1399/week_2/server/build/CMakeFiles/CMakeTutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CMakeTutorial.dir/depend

