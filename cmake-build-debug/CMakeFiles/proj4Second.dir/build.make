# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\PC\CLionProjects\proj4Second

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj4Second.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj4Second.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj4Second.dir/flags.make

CMakeFiles/proj4Second.dir/main.cpp.obj: CMakeFiles/proj4Second.dir/flags.make
CMakeFiles/proj4Second.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj4Second.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\proj4Second.dir\main.cpp.obj -c C:\Users\PC\CLionProjects\proj4Second\main.cpp

CMakeFiles/proj4Second.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4Second.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\PC\CLionProjects\proj4Second\main.cpp > CMakeFiles\proj4Second.dir\main.cpp.i

CMakeFiles/proj4Second.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4Second.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\PC\CLionProjects\proj4Second\main.cpp -o CMakeFiles\proj4Second.dir\main.cpp.s

CMakeFiles/proj4Second.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/proj4Second.dir/main.cpp.obj.requires

CMakeFiles/proj4Second.dir/main.cpp.obj.provides: CMakeFiles/proj4Second.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\proj4Second.dir\build.make CMakeFiles/proj4Second.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/proj4Second.dir/main.cpp.obj.provides

CMakeFiles/proj4Second.dir/main.cpp.obj.provides.build: CMakeFiles/proj4Second.dir/main.cpp.obj


CMakeFiles/proj4Second.dir/ttree.cpp.obj: CMakeFiles/proj4Second.dir/flags.make
CMakeFiles/proj4Second.dir/ttree.cpp.obj: ../ttree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proj4Second.dir/ttree.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\proj4Second.dir\ttree.cpp.obj -c C:\Users\PC\CLionProjects\proj4Second\ttree.cpp

CMakeFiles/proj4Second.dir/ttree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4Second.dir/ttree.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\PC\CLionProjects\proj4Second\ttree.cpp > CMakeFiles\proj4Second.dir\ttree.cpp.i

CMakeFiles/proj4Second.dir/ttree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4Second.dir/ttree.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\PC\CLionProjects\proj4Second\ttree.cpp -o CMakeFiles\proj4Second.dir\ttree.cpp.s

CMakeFiles/proj4Second.dir/ttree.cpp.obj.requires:

.PHONY : CMakeFiles/proj4Second.dir/ttree.cpp.obj.requires

CMakeFiles/proj4Second.dir/ttree.cpp.obj.provides: CMakeFiles/proj4Second.dir/ttree.cpp.obj.requires
	$(MAKE) -f CMakeFiles\proj4Second.dir\build.make CMakeFiles/proj4Second.dir/ttree.cpp.obj.provides.build
.PHONY : CMakeFiles/proj4Second.dir/ttree.cpp.obj.provides

CMakeFiles/proj4Second.dir/ttree.cpp.obj.provides.build: CMakeFiles/proj4Second.dir/ttree.cpp.obj


# Object files for target proj4Second
proj4Second_OBJECTS = \
"CMakeFiles/proj4Second.dir/main.cpp.obj" \
"CMakeFiles/proj4Second.dir/ttree.cpp.obj"

# External object files for target proj4Second
proj4Second_EXTERNAL_OBJECTS =

proj4Second.exe: CMakeFiles/proj4Second.dir/main.cpp.obj
proj4Second.exe: CMakeFiles/proj4Second.dir/ttree.cpp.obj
proj4Second.exe: CMakeFiles/proj4Second.dir/build.make
proj4Second.exe: CMakeFiles/proj4Second.dir/linklibs.rsp
proj4Second.exe: CMakeFiles/proj4Second.dir/objects1.rsp
proj4Second.exe: CMakeFiles/proj4Second.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable proj4Second.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proj4Second.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj4Second.dir/build: proj4Second.exe

.PHONY : CMakeFiles/proj4Second.dir/build

CMakeFiles/proj4Second.dir/requires: CMakeFiles/proj4Second.dir/main.cpp.obj.requires
CMakeFiles/proj4Second.dir/requires: CMakeFiles/proj4Second.dir/ttree.cpp.obj.requires

.PHONY : CMakeFiles/proj4Second.dir/requires

CMakeFiles/proj4Second.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proj4Second.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proj4Second.dir/clean

CMakeFiles/proj4Second.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\PC\CLionProjects\proj4Second C:\Users\PC\CLionProjects\proj4Second C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug C:\Users\PC\CLionProjects\proj4Second\cmake-build-debug\CMakeFiles\proj4Second.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj4Second.dir/depend

