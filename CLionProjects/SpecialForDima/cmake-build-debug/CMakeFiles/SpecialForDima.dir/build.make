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
CMAKE_SOURCE_DIR = /home/leonid/CLionProjects/SpecialForDima

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonid/CLionProjects/SpecialForDima/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SpecialForDima.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpecialForDima.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpecialForDima.dir/flags.make

CMakeFiles/SpecialForDima.dir/main.c.o: CMakeFiles/SpecialForDima.dir/flags.make
CMakeFiles/SpecialForDima.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonid/CLionProjects/SpecialForDima/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SpecialForDima.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SpecialForDima.dir/main.c.o   -c /home/leonid/CLionProjects/SpecialForDima/main.c

CMakeFiles/SpecialForDima.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpecialForDima.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonid/CLionProjects/SpecialForDima/main.c > CMakeFiles/SpecialForDima.dir/main.c.i

CMakeFiles/SpecialForDima.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpecialForDima.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonid/CLionProjects/SpecialForDima/main.c -o CMakeFiles/SpecialForDima.dir/main.c.s

CMakeFiles/SpecialForDima.dir/main.c.o.requires:

.PHONY : CMakeFiles/SpecialForDima.dir/main.c.o.requires

CMakeFiles/SpecialForDima.dir/main.c.o.provides: CMakeFiles/SpecialForDima.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/SpecialForDima.dir/build.make CMakeFiles/SpecialForDima.dir/main.c.o.provides.build
.PHONY : CMakeFiles/SpecialForDima.dir/main.c.o.provides

CMakeFiles/SpecialForDima.dir/main.c.o.provides.build: CMakeFiles/SpecialForDima.dir/main.c.o


# Object files for target SpecialForDima
SpecialForDima_OBJECTS = \
"CMakeFiles/SpecialForDima.dir/main.c.o"

# External object files for target SpecialForDima
SpecialForDima_EXTERNAL_OBJECTS =

SpecialForDima: CMakeFiles/SpecialForDima.dir/main.c.o
SpecialForDima: CMakeFiles/SpecialForDima.dir/build.make
SpecialForDima: CMakeFiles/SpecialForDima.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonid/CLionProjects/SpecialForDima/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SpecialForDima"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpecialForDima.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpecialForDima.dir/build: SpecialForDima

.PHONY : CMakeFiles/SpecialForDima.dir/build

CMakeFiles/SpecialForDima.dir/requires: CMakeFiles/SpecialForDima.dir/main.c.o.requires

.PHONY : CMakeFiles/SpecialForDima.dir/requires

CMakeFiles/SpecialForDima.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpecialForDima.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpecialForDima.dir/clean

CMakeFiles/SpecialForDima.dir/depend:
	cd /home/leonid/CLionProjects/SpecialForDima/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonid/CLionProjects/SpecialForDima /home/leonid/CLionProjects/SpecialForDima /home/leonid/CLionProjects/SpecialForDima/cmake-build-debug /home/leonid/CLionProjects/SpecialForDima/cmake-build-debug /home/leonid/CLionProjects/SpecialForDima/cmake-build-debug/CMakeFiles/SpecialForDima.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpecialForDima.dir/depend
