# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build

# Include any dependencies generated for this target.
include CMakeFiles/googletest1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/googletest1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/googletest1.dir/flags.make

CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o: CMakeFiles/googletest1.dir/flags.make
CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o: ../googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o -c /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/googletest/googletest/src/gtest-all.cc

CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/googletest/googletest/src/gtest-all.cc > CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.i

CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/googletest/googletest/src/gtest-all.cc -o CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.s

# Object files for target googletest1
googletest1_OBJECTS = \
"CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o"

# External object files for target googletest1
googletest1_EXTERNAL_OBJECTS =

libgoogletest1.a: CMakeFiles/googletest1.dir/googletest/googletest/src/gtest-all.cc.o
libgoogletest1.a: CMakeFiles/googletest1.dir/build.make
libgoogletest1.a: CMakeFiles/googletest1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgoogletest1.a"
	$(CMAKE_COMMAND) -P CMakeFiles/googletest1.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/googletest1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/googletest1.dir/build: libgoogletest1.a

.PHONY : CMakeFiles/googletest1.dir/build

CMakeFiles/googletest1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletest1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletest1.dir/clean

CMakeFiles/googletest1.dir/depend:
	cd /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build /home/AD/tcrussar/DossierPartage/S6/PMP/TP1/parser/build/CMakeFiles/googletest1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletest1.dir/depend
