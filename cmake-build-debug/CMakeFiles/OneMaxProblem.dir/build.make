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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OneMaxProblem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OneMaxProblem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OneMaxProblem.dir/flags.make

CMakeFiles/OneMaxProblem.dir/main.cpp.o: CMakeFiles/OneMaxProblem.dir/flags.make
CMakeFiles/OneMaxProblem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OneMaxProblem.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OneMaxProblem.dir/main.cpp.o -c /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/main.cpp

CMakeFiles/OneMaxProblem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OneMaxProblem.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/main.cpp > CMakeFiles/OneMaxProblem.dir/main.cpp.i

CMakeFiles/OneMaxProblem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OneMaxProblem.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/main.cpp -o CMakeFiles/OneMaxProblem.dir/main.cpp.s

CMakeFiles/OneMaxProblem.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OneMaxProblem.dir/main.cpp.o.requires

CMakeFiles/OneMaxProblem.dir/main.cpp.o.provides: CMakeFiles/OneMaxProblem.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OneMaxProblem.dir/build.make CMakeFiles/OneMaxProblem.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OneMaxProblem.dir/main.cpp.o.provides

CMakeFiles/OneMaxProblem.dir/main.cpp.o.provides.build: CMakeFiles/OneMaxProblem.dir/main.cpp.o


CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o: CMakeFiles/OneMaxProblem.dir/flags.make
CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o: ../GeneticAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o -c /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/GeneticAlgorithm.cpp

CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/GeneticAlgorithm.cpp > CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.i

CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/GeneticAlgorithm.cpp -o CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.s

CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.requires:

.PHONY : CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.requires

CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.provides: CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/OneMaxProblem.dir/build.make CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.provides.build
.PHONY : CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.provides

CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.provides.build: CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o


# Object files for target OneMaxProblem
OneMaxProblem_OBJECTS = \
"CMakeFiles/OneMaxProblem.dir/main.cpp.o" \
"CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o"

# External object files for target OneMaxProblem
OneMaxProblem_EXTERNAL_OBJECTS =

OneMaxProblem: CMakeFiles/OneMaxProblem.dir/main.cpp.o
OneMaxProblem: CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o
OneMaxProblem: CMakeFiles/OneMaxProblem.dir/build.make
OneMaxProblem: CMakeFiles/OneMaxProblem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OneMaxProblem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OneMaxProblem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OneMaxProblem.dir/build: OneMaxProblem

.PHONY : CMakeFiles/OneMaxProblem.dir/build

CMakeFiles/OneMaxProblem.dir/requires: CMakeFiles/OneMaxProblem.dir/main.cpp.o.requires
CMakeFiles/OneMaxProblem.dir/requires: CMakeFiles/OneMaxProblem.dir/GeneticAlgorithm.cpp.o.requires

.PHONY : CMakeFiles/OneMaxProblem.dir/requires

CMakeFiles/OneMaxProblem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OneMaxProblem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OneMaxProblem.dir/clean

CMakeFiles/OneMaxProblem.dir/depend:
	cd /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug /Users/mcangny/CLionProjects/OneMaxOptimizationGenetic/cmake-build-debug/CMakeFiles/OneMaxProblem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OneMaxProblem.dir/depend

