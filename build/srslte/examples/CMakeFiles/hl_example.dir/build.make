# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/orange/srslte_m

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/orange/srslte_m/build

# Include any dependencies generated for this target.
include srslte/examples/CMakeFiles/hl_example.dir/depend.make

# Include the progress variables for this target.
include srslte/examples/CMakeFiles/hl_example.dir/progress.make

# Include the compile flags for this target's objects.
include srslte/examples/CMakeFiles/hl_example.dir/flags.make

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o: srslte/examples/CMakeFiles/hl_example.dir/flags.make
srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o: ../srslte/examples/hl_example.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hl_example.dir/hl_example.c.o   -c /home/orange/srslte_m/srslte/examples/hl_example.c

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hl_example.dir/hl_example.c.i"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/orange/srslte_m/srslte/examples/hl_example.c > CMakeFiles/hl_example.dir/hl_example.c.i

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hl_example.dir/hl_example.c.s"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/orange/srslte_m/srslte/examples/hl_example.c -o CMakeFiles/hl_example.dir/hl_example.c.s

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.requires:
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.requires

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.provides: srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.requires
	$(MAKE) -f srslte/examples/CMakeFiles/hl_example.dir/build.make srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.provides.build
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.provides

srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.provides.build: srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o

# Object files for target hl_example
hl_example_OBJECTS = \
"CMakeFiles/hl_example.dir/hl_example.c.o"

# External object files for target hl_example
hl_example_EXTERNAL_OBJECTS =

srslte/examples/hl_example: srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o
srslte/examples/hl_example: srslte/examples/CMakeFiles/hl_example.dir/build.make
srslte/examples/hl_example: srslte/lib/libsrslte.so
srslte/examples/hl_example: /usr/lib/i386-linux-gnu/libfftw3f.so
srslte/examples/hl_example: /usr/local/lib/libvolk.so
srslte/examples/hl_example: srslte/examples/CMakeFiles/hl_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable hl_example"
	cd /home/orange/srslte_m/build/srslte/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hl_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srslte/examples/CMakeFiles/hl_example.dir/build: srslte/examples/hl_example
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/build

srslte/examples/CMakeFiles/hl_example.dir/requires: srslte/examples/CMakeFiles/hl_example.dir/hl_example.c.o.requires
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/requires

srslte/examples/CMakeFiles/hl_example.dir/clean:
	cd /home/orange/srslte_m/build/srslte/examples && $(CMAKE_COMMAND) -P CMakeFiles/hl_example.dir/cmake_clean.cmake
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/clean

srslte/examples/CMakeFiles/hl_example.dir/depend:
	cd /home/orange/srslte_m/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orange/srslte_m /home/orange/srslte_m/srslte/examples /home/orange/srslte_m/build /home/orange/srslte_m/build/srslte/examples /home/orange/srslte_m/build/srslte/examples/CMakeFiles/hl_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srslte/examples/CMakeFiles/hl_example.dir/depend

