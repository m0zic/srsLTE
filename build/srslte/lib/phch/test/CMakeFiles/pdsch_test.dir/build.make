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
include srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/depend.make

# Include the progress variables for this target.
include srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/progress.make

# Include the compile flags for this target's objects.
include srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/flags.make

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/flags.make
srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o: ../srslte/lib/phch/test/pdsch_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o"
	cd /home/orange/srslte_m/build/srslte/lib/phch/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pdsch_test.dir/pdsch_test.c.o   -c /home/orange/srslte_m/srslte/lib/phch/test/pdsch_test.c

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pdsch_test.dir/pdsch_test.c.i"
	cd /home/orange/srslte_m/build/srslte/lib/phch/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/orange/srslte_m/srslte/lib/phch/test/pdsch_test.c > CMakeFiles/pdsch_test.dir/pdsch_test.c.i

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pdsch_test.dir/pdsch_test.c.s"
	cd /home/orange/srslte_m/build/srslte/lib/phch/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/orange/srslte_m/srslte/lib/phch/test/pdsch_test.c -o CMakeFiles/pdsch_test.dir/pdsch_test.c.s

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.requires:
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.requires

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.provides: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.requires
	$(MAKE) -f srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/build.make srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.provides.build
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.provides

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.provides.build: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o

# Object files for target pdsch_test
pdsch_test_OBJECTS = \
"CMakeFiles/pdsch_test.dir/pdsch_test.c.o"

# External object files for target pdsch_test
pdsch_test_EXTERNAL_OBJECTS =

srslte/lib/phch/test/pdsch_test: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o
srslte/lib/phch/test/pdsch_test: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/build.make
srslte/lib/phch/test/pdsch_test: srslte/lib/libsrslte.so
srslte/lib/phch/test/pdsch_test: /usr/lib/i386-linux-gnu/libfftw3f.so
srslte/lib/phch/test/pdsch_test: /usr/local/lib/libvolk.so
srslte/lib/phch/test/pdsch_test: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pdsch_test"
	cd /home/orange/srslte_m/build/srslte/lib/phch/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pdsch_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/build: srslte/lib/phch/test/pdsch_test
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/build

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/requires: srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/pdsch_test.c.o.requires
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/requires

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/clean:
	cd /home/orange/srslte_m/build/srslte/lib/phch/test && $(CMAKE_COMMAND) -P CMakeFiles/pdsch_test.dir/cmake_clean.cmake
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/clean

srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/depend:
	cd /home/orange/srslte_m/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orange/srslte_m /home/orange/srslte_m/srslte/lib/phch/test /home/orange/srslte_m/build /home/orange/srslte_m/build/srslte/lib/phch/test /home/orange/srslte_m/build/srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srslte/lib/phch/test/CMakeFiles/pdsch_test.dir/depend

