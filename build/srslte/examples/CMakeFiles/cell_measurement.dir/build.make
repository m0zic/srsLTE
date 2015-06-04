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
include srslte/examples/CMakeFiles/cell_measurement.dir/depend.make

# Include the progress variables for this target.
include srslte/examples/CMakeFiles/cell_measurement.dir/progress.make

# Include the compile flags for this target's objects.
include srslte/examples/CMakeFiles/cell_measurement.dir/flags.make

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o: srslte/examples/CMakeFiles/cell_measurement.dir/flags.make
srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o: ../srslte/examples/cell_measurement.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cell_measurement.dir/cell_measurement.c.o   -c /home/orange/srslte_m/srslte/examples/cell_measurement.c

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cell_measurement.dir/cell_measurement.c.i"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/orange/srslte_m/srslte/examples/cell_measurement.c > CMakeFiles/cell_measurement.dir/cell_measurement.c.i

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cell_measurement.dir/cell_measurement.c.s"
	cd /home/orange/srslte_m/build/srslte/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/orange/srslte_m/srslte/examples/cell_measurement.c -o CMakeFiles/cell_measurement.dir/cell_measurement.c.s

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.requires:
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.requires

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.provides: srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.requires
	$(MAKE) -f srslte/examples/CMakeFiles/cell_measurement.dir/build.make srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.provides.build
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.provides

srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.provides.build: srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o

# Object files for target cell_measurement
cell_measurement_OBJECTS = \
"CMakeFiles/cell_measurement.dir/cell_measurement.c.o"

# External object files for target cell_measurement
cell_measurement_EXTERNAL_OBJECTS =

srslte/examples/cell_measurement: srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o
srslte/examples/cell_measurement: srslte/examples/CMakeFiles/cell_measurement.dir/build.make
srslte/examples/cell_measurement: srslte/lib/libsrslte.so
srslte/examples/cell_measurement: srslte/lib/libsrslte_uhd.so
srslte/examples/cell_measurement: /usr/lib/i386-linux-gnu/libfftw3f.so
srslte/examples/cell_measurement: /usr/local/lib/libvolk.so
srslte/examples/cell_measurement: srslte/examples/CMakeFiles/cell_measurement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable cell_measurement"
	cd /home/orange/srslte_m/build/srslte/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cell_measurement.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srslte/examples/CMakeFiles/cell_measurement.dir/build: srslte/examples/cell_measurement
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/build

srslte/examples/CMakeFiles/cell_measurement.dir/requires: srslte/examples/CMakeFiles/cell_measurement.dir/cell_measurement.c.o.requires
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/requires

srslte/examples/CMakeFiles/cell_measurement.dir/clean:
	cd /home/orange/srslte_m/build/srslte/examples && $(CMAKE_COMMAND) -P CMakeFiles/cell_measurement.dir/cmake_clean.cmake
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/clean

srslte/examples/CMakeFiles/cell_measurement.dir/depend:
	cd /home/orange/srslte_m/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orange/srslte_m /home/orange/srslte_m/srslte/examples /home/orange/srslte_m/build /home/orange/srslte_m/build/srslte/examples /home/orange/srslte_m/build/srslte/examples/CMakeFiles/cell_measurement.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srslte/examples/CMakeFiles/cell_measurement.dir/depend
