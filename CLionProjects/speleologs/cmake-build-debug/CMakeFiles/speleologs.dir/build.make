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
CMAKE_COMMAND = /home/leonid/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/leonid/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonid/CLionProjects/speleologs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonid/CLionProjects/speleologs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/speleologs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/speleologs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/speleologs.dir/flags.make

CMakeFiles/speleologs.dir/main.cpp.o: CMakeFiles/speleologs.dir/flags.make
CMakeFiles/speleologs.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonid/CLionProjects/speleologs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/speleologs.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/speleologs.dir/main.cpp.o -c /home/leonid/CLionProjects/speleologs/main.cpp

CMakeFiles/speleologs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/speleologs.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonid/CLionProjects/speleologs/main.cpp > CMakeFiles/speleologs.dir/main.cpp.i

CMakeFiles/speleologs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/speleologs.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonid/CLionProjects/speleologs/main.cpp -o CMakeFiles/speleologs.dir/main.cpp.s

CMakeFiles/speleologs.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/speleologs.dir/main.cpp.o.requires

CMakeFiles/speleologs.dir/main.cpp.o.provides: CMakeFiles/speleologs.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/speleologs.dir/build.make CMakeFiles/speleologs.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/speleologs.dir/main.cpp.o.provides

CMakeFiles/speleologs.dir/main.cpp.o.provides.build: CMakeFiles/speleologs.dir/main.cpp.o


# Object files for target speleologs
speleologs_OBJECTS = \
"CMakeFiles/speleologs.dir/main.cpp.o"

# External object files for target speleologs
speleologs_EXTERNAL_OBJECTS =

speleologs: CMakeFiles/speleologs.dir/main.cpp.o
speleologs: CMakeFiles/speleologs.dir/build.make
speleologs: CMakeFiles/speleologs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonid/CLionProjects/speleologs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable speleologs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/speleologs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/speleologs.dir/build: speleologs

.PHONY : CMakeFiles/speleologs.dir/build

CMakeFiles/speleologs.dir/requires: CMakeFiles/speleologs.dir/main.cpp.o.requires

.PHONY : CMakeFiles/speleologs.dir/requires

CMakeFiles/speleologs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/speleologs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/speleologs.dir/clean

CMakeFiles/speleologs.dir/depend:
	cd /home/leonid/CLionProjects/speleologs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonid/CLionProjects/speleologs /home/leonid/CLionProjects/speleologs /home/leonid/CLionProjects/speleologs/cmake-build-debug /home/leonid/CLionProjects/speleologs/cmake-build-debug /home/leonid/CLionProjects/speleologs/cmake-build-debug/CMakeFiles/speleologs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/speleologs.dir/depend

