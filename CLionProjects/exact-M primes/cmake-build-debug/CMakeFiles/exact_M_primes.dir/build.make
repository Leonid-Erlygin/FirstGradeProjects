# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/leonid/.local/share/umake/ide/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/leonid/.local/share/umake/ide/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/leonid/CLionProjects/exact-M primes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/leonid/CLionProjects/exact-M primes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/exact_M_primes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exact_M_primes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exact_M_primes.dir/flags.make

CMakeFiles/exact_M_primes.dir/main.cpp.o: CMakeFiles/exact_M_primes.dir/flags.make
CMakeFiles/exact_M_primes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leonid/CLionProjects/exact-M primes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exact_M_primes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exact_M_primes.dir/main.cpp.o -c "/home/leonid/CLionProjects/exact-M primes/main.cpp"

CMakeFiles/exact_M_primes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exact_M_primes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leonid/CLionProjects/exact-M primes/main.cpp" > CMakeFiles/exact_M_primes.dir/main.cpp.i

CMakeFiles/exact_M_primes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exact_M_primes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leonid/CLionProjects/exact-M primes/main.cpp" -o CMakeFiles/exact_M_primes.dir/main.cpp.s

CMakeFiles/exact_M_primes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/exact_M_primes.dir/main.cpp.o.requires

CMakeFiles/exact_M_primes.dir/main.cpp.o.provides: CMakeFiles/exact_M_primes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/exact_M_primes.dir/build.make CMakeFiles/exact_M_primes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/exact_M_primes.dir/main.cpp.o.provides

CMakeFiles/exact_M_primes.dir/main.cpp.o.provides.build: CMakeFiles/exact_M_primes.dir/main.cpp.o


# Object files for target exact_M_primes
exact_M_primes_OBJECTS = \
"CMakeFiles/exact_M_primes.dir/main.cpp.o"

# External object files for target exact_M_primes
exact_M_primes_EXTERNAL_OBJECTS =

exact_M_primes: CMakeFiles/exact_M_primes.dir/main.cpp.o
exact_M_primes: CMakeFiles/exact_M_primes.dir/build.make
exact_M_primes: CMakeFiles/exact_M_primes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/leonid/CLionProjects/exact-M primes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exact_M_primes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exact_M_primes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exact_M_primes.dir/build: exact_M_primes

.PHONY : CMakeFiles/exact_M_primes.dir/build

CMakeFiles/exact_M_primes.dir/requires: CMakeFiles/exact_M_primes.dir/main.cpp.o.requires

.PHONY : CMakeFiles/exact_M_primes.dir/requires

CMakeFiles/exact_M_primes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exact_M_primes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exact_M_primes.dir/clean

CMakeFiles/exact_M_primes.dir/depend:
	cd "/home/leonid/CLionProjects/exact-M primes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/leonid/CLionProjects/exact-M primes" "/home/leonid/CLionProjects/exact-M primes" "/home/leonid/CLionProjects/exact-M primes/cmake-build-debug" "/home/leonid/CLionProjects/exact-M primes/cmake-build-debug" "/home/leonid/CLionProjects/exact-M primes/cmake-build-debug/CMakeFiles/exact_M_primes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exact_M_primes.dir/depend
