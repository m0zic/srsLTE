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
include srslte/lib/sync/test/CMakeFiles/pss_file.dir/depend.make

# Include the progress variables for this target.
include srslte/lib/sync/test/CMakeFiles/pss_file.dir/progress.make

# Include the compile flags for this target's objects.
include srslte/lib/sync/test/CMakeFiles/pss_file.dir/flags.make

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o: srslte/lib/sync/test/CMakeFiles/pss_file.dir/flags.make
srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o: ../srslte/lib/sync/test/pss_file.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o"
	cd /home/orange/srslte_m/build/srslte/lib/sync/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pss_file.dir/pss_file.c.o   -c /home/orange/srslte_m/srslte/lib/sync/test/pss_file.c

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pss_file.dir/pss_file.c.i"
	cd /home/orange/srslte_m/build/srslte/lib/sync/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/orange/srslte_m/srslte/lib/sync/test/pss_file.c > CMakeFiles/pss_file.dir/pss_file.c.i

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pss_file.dir/pss_file.c.s"
	cd /home/orange/srslte_m/build/srslte/lib/sync/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/orange/srslte_m/srslte/lib/sync/test/pss_file.c -o CMakeFiles/pss_file.dir/pss_file.c.s

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.requires:
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.requires

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.provides: srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.requires
	$(MAKE) -f srslte/lib/sync/test/CMakeFiles/pss_file.dir/build.make srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.provides.build
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.provides

srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.provides.build: srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o

# Object files for target pss_file
pss_file_OBJECTS = \
"CMakeFiles/pss_file.dir/pss_file.c.o"

# External object files for target pss_file
pss_file_EXTERNAL_OBJECTS =

srslte/lib/sync/test/pss_file: srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o
srslte/lib/sync/test/pss_file: srslte/lib/sync/test/CMakeFiles/pss_file.dir/build.make
srslte/lib/sync/test/pss_file: srslte/lib/libsrslte.so
srslte/lib/sync/test/pss_file: /usr/local/lib/libsrsgui.so
srslte/lib/sync/test/pss_file: /usr/lib/i386-linux-gnu/libfftw3f.so
srslte/lib/sync/test/pss_file: /usr/local/lib/libvolk.so
srslte/lib/sync/test/pss_file: srslte/lib/sync/test/CMakeFiles/pss_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pss_file"
	cd /home/orange/srslte_m/build/srslte/lib/sync/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pss_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srslte/lib/sync/test/CMakeFiles/pss_file.dir/build: srslte/lib/sync/test/pss_file
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/build

srslte/lib/sync/test/CMakeFiles/pss_file.dir/requires: srslte/lib/sync/test/CMakeFiles/pss_file.dir/pss_file.c.o.requires
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/requires

srslte/lib/sync/test/CMakeFiles/pss_file.dir/clean:
	cd /home/orange/srslte_m/build/srslte/lib/sync/test && $(CMAKE_COMMAND) -P CMakeFiles/pss_file.dir/cmake_clean.cmake
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/clean

srslte/lib/sync/test/CMakeFiles/pss_file.dir/depend:
	cd /home/orange/srslte_m/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orange/srslte_m /home/orange/srslte_m/srslte/lib/sync/test /home/orange/srslte_m/build /home/orange/srslte_m/build/srslte/lib/sync/test /home/orange/srslte_m/build/srslte/lib/sync/test/CMakeFiles/pss_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srslte/lib/sync/test/CMakeFiles/pss_file.dir/depend

