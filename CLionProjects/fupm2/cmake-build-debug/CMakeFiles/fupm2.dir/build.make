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
CMAKE_SOURCE_DIR = /home/leonid/CLionProjects/fupm2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonid/CLionProjects/fupm2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fupm2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fupm2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fupm2.dir/flags.make

CMakeFiles/fupm2.dir/main.cpp.o: CMakeFiles/fupm2.dir/flags.make
CMakeFiles/fupm2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonid/CLionProjects/fupm2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fupm2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fupm2.dir/main.cpp.o -c /home/leonid/CLionProjects/fupm2/main.cpp

CMakeFiles/fupm2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fupm2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonid/CLionProjects/fupm2/main.cpp > CMakeFiles/fupm2.dir/main.cpp.i

CMakeFiles/fupm2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fupm2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonid/CLionProjects/fupm2/main.cpp -o CMakeFiles/fupm2.dir/main.cpp.s

CMakeFiles/fupm2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fupm2.dir/main.cpp.o.requires

CMakeFiles/fupm2.dir/main.cpp.o.provides: CMakeFiles/fupm2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fupm2.dir/build.make CMakeFiles/fupm2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fupm2.dir/main.cpp.o.provides

CMakeFiles/fupm2.dir/main.cpp.o.provides.build: CMakeFiles/fupm2.dir/main.cpp.o


# Object files for target fupm2
fupm2_OBJECTS = \
"CMakeFiles/fupm2.dir/main.cpp.o"

# External object files for target fupm2
fupm2_EXTERNAL_OBJECTS =

fupm2: CMakeFiles/fupm2.dir/main.cpp.o
fupm2: CMakeFiles/fupm2.dir/build.make
fupm2: CMakeFiles/fupm2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonid/CLionProjects/fupm2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fupm2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fupm2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fupm2.dir/build: fupm2

.PHONY : CMakeFiles/fupm2.dir/build

CMakeFiles/fupm2.dir/requires: CMakeFiles/fupm2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fupm2.dir/requires

CMakeFiles/fupm2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fupm2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fupm2.dir/clean

CMakeFiles/fupm2.dir/depend:
	cd /home/leonid/CLionProjects/fupm2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonid/CLionProjects/fupm2 /home/leonid/CLionProjects/fupm2 /home/leonid/CLionProjects/fupm2/cmake-build-debug /home/leonid/CLionProjects/fupm2/cmake-build-debug /home/leonid/CLionProjects/fupm2/cmake-build-debug/CMakeFiles/fupm2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fupm2.dir/depend
