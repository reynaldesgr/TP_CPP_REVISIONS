# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build

# Include any dependencies generated for this target.
include CMakeFiles/exam.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exam.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exam.dir/flags.make

CMakeFiles/exam.dir/src/inventory.cpp.o: CMakeFiles/exam.dir/flags.make
CMakeFiles/exam.dir/src/inventory.cpp.o: ../src/inventory.cpp
CMakeFiles/exam.dir/src/inventory.cpp.o: CMakeFiles/exam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exam.dir/src/inventory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exam.dir/src/inventory.cpp.o -MF CMakeFiles/exam.dir/src/inventory.cpp.o.d -o CMakeFiles/exam.dir/src/inventory.cpp.o -c /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/inventory.cpp

CMakeFiles/exam.dir/src/inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam.dir/src/inventory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/inventory.cpp > CMakeFiles/exam.dir/src/inventory.cpp.i

CMakeFiles/exam.dir/src/inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam.dir/src/inventory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/inventory.cpp -o CMakeFiles/exam.dir/src/inventory.cpp.s

CMakeFiles/exam.dir/src/product.cpp.o: CMakeFiles/exam.dir/flags.make
CMakeFiles/exam.dir/src/product.cpp.o: ../src/product.cpp
CMakeFiles/exam.dir/src/product.cpp.o: CMakeFiles/exam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exam.dir/src/product.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exam.dir/src/product.cpp.o -MF CMakeFiles/exam.dir/src/product.cpp.o.d -o CMakeFiles/exam.dir/src/product.cpp.o -c /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/product.cpp

CMakeFiles/exam.dir/src/product.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam.dir/src/product.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/product.cpp > CMakeFiles/exam.dir/src/product.cpp.i

CMakeFiles/exam.dir/src/product.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam.dir/src/product.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/product.cpp -o CMakeFiles/exam.dir/src/product.cpp.s

CMakeFiles/exam.dir/src/order.cpp.o: CMakeFiles/exam.dir/flags.make
CMakeFiles/exam.dir/src/order.cpp.o: ../src/order.cpp
CMakeFiles/exam.dir/src/order.cpp.o: CMakeFiles/exam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exam.dir/src/order.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exam.dir/src/order.cpp.o -MF CMakeFiles/exam.dir/src/order.cpp.o.d -o CMakeFiles/exam.dir/src/order.cpp.o -c /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/order.cpp

CMakeFiles/exam.dir/src/order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam.dir/src/order.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/order.cpp > CMakeFiles/exam.dir/src/order.cpp.i

CMakeFiles/exam.dir/src/order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam.dir/src/order.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/src/order.cpp -o CMakeFiles/exam.dir/src/order.cpp.s

CMakeFiles/exam.dir/test/tests.cpp.o: CMakeFiles/exam.dir/flags.make
CMakeFiles/exam.dir/test/tests.cpp.o: ../test/tests.cpp
CMakeFiles/exam.dir/test/tests.cpp.o: CMakeFiles/exam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exam.dir/test/tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exam.dir/test/tests.cpp.o -MF CMakeFiles/exam.dir/test/tests.cpp.o.d -o CMakeFiles/exam.dir/test/tests.cpp.o -c /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/tests.cpp

CMakeFiles/exam.dir/test/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam.dir/test/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/tests.cpp > CMakeFiles/exam.dir/test/tests.cpp.i

CMakeFiles/exam.dir/test/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam.dir/test/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/tests.cpp -o CMakeFiles/exam.dir/test/tests.cpp.s

CMakeFiles/exam.dir/test/catch.cpp.o: CMakeFiles/exam.dir/flags.make
CMakeFiles/exam.dir/test/catch.cpp.o: ../test/catch.cpp
CMakeFiles/exam.dir/test/catch.cpp.o: CMakeFiles/exam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exam.dir/test/catch.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exam.dir/test/catch.cpp.o -MF CMakeFiles/exam.dir/test/catch.cpp.o.d -o CMakeFiles/exam.dir/test/catch.cpp.o -c /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/catch.cpp

CMakeFiles/exam.dir/test/catch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam.dir/test/catch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/catch.cpp > CMakeFiles/exam.dir/test/catch.cpp.i

CMakeFiles/exam.dir/test/catch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam.dir/test/catch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/test/catch.cpp -o CMakeFiles/exam.dir/test/catch.cpp.s

# Object files for target exam
exam_OBJECTS = \
"CMakeFiles/exam.dir/src/inventory.cpp.o" \
"CMakeFiles/exam.dir/src/product.cpp.o" \
"CMakeFiles/exam.dir/src/order.cpp.o" \
"CMakeFiles/exam.dir/test/tests.cpp.o" \
"CMakeFiles/exam.dir/test/catch.cpp.o"

# External object files for target exam
exam_EXTERNAL_OBJECTS =

exam: CMakeFiles/exam.dir/src/inventory.cpp.o
exam: CMakeFiles/exam.dir/src/product.cpp.o
exam: CMakeFiles/exam.dir/src/order.cpp.o
exam: CMakeFiles/exam.dir/test/tests.cpp.o
exam: CMakeFiles/exam.dir/test/catch.cpp.o
exam: CMakeFiles/exam.dir/build.make
exam: CMakeFiles/exam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable exam"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exam.dir/build: exam
.PHONY : CMakeFiles/exam.dir/build

CMakeFiles/exam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exam.dir/clean

CMakeFiles/exam.dir/depend:
	cd /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02 /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02 /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build /home/rsegerie/Bureau/TP_CPP_REVISIONS/EXAM-02/build/CMakeFiles/exam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exam.dir/depend

