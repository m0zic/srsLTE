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
include srsapps/common/CMakeFiles/srsapps_common.dir/depend.make

# Include the progress variables for this target.
include srsapps/common/CMakeFiles/srsapps_common.dir/progress.make

# Include the compile flags for this target's objects.
include srsapps/common/CMakeFiles/srsapps_common.dir/flags.make

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o: srsapps/common/CMakeFiles/srsapps_common.dir/flags.make
srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o: ../srsapps/common/src/log_stdout.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o -c /home/orange/srslte_m/srsapps/common/src/log_stdout.cc

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsapps_common.dir/src/log_stdout.cc.i"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/orange/srslte_m/srsapps/common/src/log_stdout.cc > CMakeFiles/srsapps_common.dir/src/log_stdout.cc.i

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsapps_common.dir/src/log_stdout.cc.s"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/orange/srslte_m/srsapps/common/src/log_stdout.cc -o CMakeFiles/srsapps_common.dir/src/log_stdout.cc.s

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.requires:
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.requires

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.provides: srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.requires
	$(MAKE) -f srsapps/common/CMakeFiles/srsapps_common.dir/build.make srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.provides.build
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.provides

srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.provides.build: srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o: srsapps/common/CMakeFiles/srsapps_common.dir/flags.make
srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o: ../srsapps/common/src/tti_sync_cv.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o -c /home/orange/srslte_m/srsapps/common/src/tti_sync_cv.cc

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.i"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/orange/srslte_m/srsapps/common/src/tti_sync_cv.cc > CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.i

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.s"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/orange/srslte_m/srsapps/common/src/tti_sync_cv.cc -o CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.s

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.requires:
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.requires

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.provides: srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.requires
	$(MAKE) -f srsapps/common/CMakeFiles/srsapps_common.dir/build.make srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.provides.build
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.provides

srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.provides.build: srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o: srsapps/common/CMakeFiles/srsapps_common.dir/flags.make
srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o: ../srsapps/common/src/qbuff.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/srsapps_common.dir/src/qbuff.cc.o -c /home/orange/srslte_m/srsapps/common/src/qbuff.cc

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsapps_common.dir/src/qbuff.cc.i"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/orange/srslte_m/srsapps/common/src/qbuff.cc > CMakeFiles/srsapps_common.dir/src/qbuff.cc.i

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsapps_common.dir/src/qbuff.cc.s"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/orange/srslte_m/srsapps/common/src/qbuff.cc -o CMakeFiles/srsapps_common.dir/src/qbuff.cc.s

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.requires:
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.requires

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.provides: srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.requires
	$(MAKE) -f srsapps/common/CMakeFiles/srsapps_common.dir/build.make srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.provides.build
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.provides

srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.provides.build: srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o: srsapps/common/CMakeFiles/srsapps_common.dir/flags.make
srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o: ../srsapps/common/src/queue.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/orange/srslte_m/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/srsapps_common.dir/src/queue.cc.o -c /home/orange/srslte_m/srsapps/common/src/queue.cc

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsapps_common.dir/src/queue.cc.i"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/orange/srslte_m/srsapps/common/src/queue.cc > CMakeFiles/srsapps_common.dir/src/queue.cc.i

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsapps_common.dir/src/queue.cc.s"
	cd /home/orange/srslte_m/build/srsapps/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/orange/srslte_m/srsapps/common/src/queue.cc -o CMakeFiles/srsapps_common.dir/src/queue.cc.s

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.requires:
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.requires

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.provides: srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.requires
	$(MAKE) -f srsapps/common/CMakeFiles/srsapps_common.dir/build.make srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.provides.build
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.provides

srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.provides.build: srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o

# Object files for target srsapps_common
srsapps_common_OBJECTS = \
"CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o" \
"CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o" \
"CMakeFiles/srsapps_common.dir/src/qbuff.cc.o" \
"CMakeFiles/srsapps_common.dir/src/queue.cc.o"

# External object files for target srsapps_common
srsapps_common_EXTERNAL_OBJECTS =

srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o
srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o
srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o
srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o
srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/build.make
srsapps/common/libsrsapps_common.so: srsapps/common/CMakeFiles/srsapps_common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libsrsapps_common.so"
	cd /home/orange/srslte_m/build/srsapps/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/srsapps_common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srsapps/common/CMakeFiles/srsapps_common.dir/build: srsapps/common/libsrsapps_common.so
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/build

srsapps/common/CMakeFiles/srsapps_common.dir/requires: srsapps/common/CMakeFiles/srsapps_common.dir/src/log_stdout.cc.o.requires
srsapps/common/CMakeFiles/srsapps_common.dir/requires: srsapps/common/CMakeFiles/srsapps_common.dir/src/tti_sync_cv.cc.o.requires
srsapps/common/CMakeFiles/srsapps_common.dir/requires: srsapps/common/CMakeFiles/srsapps_common.dir/src/qbuff.cc.o.requires
srsapps/common/CMakeFiles/srsapps_common.dir/requires: srsapps/common/CMakeFiles/srsapps_common.dir/src/queue.cc.o.requires
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/requires

srsapps/common/CMakeFiles/srsapps_common.dir/clean:
	cd /home/orange/srslte_m/build/srsapps/common && $(CMAKE_COMMAND) -P CMakeFiles/srsapps_common.dir/cmake_clean.cmake
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/clean

srsapps/common/CMakeFiles/srsapps_common.dir/depend:
	cd /home/orange/srslte_m/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orange/srslte_m /home/orange/srslte_m/srsapps/common /home/orange/srslte_m/build /home/orange/srslte_m/build/srsapps/common /home/orange/srslte_m/build/srsapps/common/CMakeFiles/srsapps_common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srsapps/common/CMakeFiles/srsapps_common.dir/depend
