# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/jyc/software/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jyc/software/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jyc/mygithub/wheels

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jyc/mygithub/wheels/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Process_lock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Process_lock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Process_lock.dir/flags.make

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o: CMakeFiles/Process_lock.dir/flags.make
CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o: ../Process_lock/test_lock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jyc/mygithub/wheels/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o   -c /home/jyc/mygithub/wheels/Process_lock/test_lock.c

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jyc/mygithub/wheels/Process_lock/test_lock.c > CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.i

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jyc/mygithub/wheels/Process_lock/test_lock.c -o CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.s

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.requires:

.PHONY : CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.requires

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.provides: CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.requires
	$(MAKE) -f CMakeFiles/Process_lock.dir/build.make CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.provides.build
.PHONY : CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.provides

CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.provides.build: CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o


CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o: CMakeFiles/Process_lock.dir/flags.make
CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o: ../Process_lock/Process_lock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jyc/mygithub/wheels/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o   -c /home/jyc/mygithub/wheels/Process_lock/Process_lock.c

CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jyc/mygithub/wheels/Process_lock/Process_lock.c > CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.i

CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jyc/mygithub/wheels/Process_lock/Process_lock.c -o CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.s

CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.requires:

.PHONY : CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.requires

CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.provides: CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.requires
	$(MAKE) -f CMakeFiles/Process_lock.dir/build.make CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.provides.build
.PHONY : CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.provides

CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.provides.build: CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o


# Object files for target Process_lock
Process_lock_OBJECTS = \
"CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o" \
"CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o"

# External object files for target Process_lock
Process_lock_EXTERNAL_OBJECTS =

Process_lock: CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o
Process_lock: CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o
Process_lock: CMakeFiles/Process_lock.dir/build.make
Process_lock: CMakeFiles/Process_lock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jyc/mygithub/wheels/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Process_lock"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Process_lock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Process_lock.dir/build: Process_lock

.PHONY : CMakeFiles/Process_lock.dir/build

CMakeFiles/Process_lock.dir/requires: CMakeFiles/Process_lock.dir/Process_lock/test_lock.c.o.requires
CMakeFiles/Process_lock.dir/requires: CMakeFiles/Process_lock.dir/Process_lock/Process_lock.c.o.requires

.PHONY : CMakeFiles/Process_lock.dir/requires

CMakeFiles/Process_lock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Process_lock.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Process_lock.dir/clean

CMakeFiles/Process_lock.dir/depend:
	cd /home/jyc/mygithub/wheels/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jyc/mygithub/wheels /home/jyc/mygithub/wheels /home/jyc/mygithub/wheels/cmake-build-debug /home/jyc/mygithub/wheels/cmake-build-debug /home/jyc/mygithub/wheels/cmake-build-debug/CMakeFiles/Process_lock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Process_lock.dir/depend

