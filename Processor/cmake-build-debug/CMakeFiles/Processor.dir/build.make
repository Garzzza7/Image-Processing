# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\piotr\Desktop\Image-Processing\Processor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Processor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Processor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Processor.dir/flags.make

CMakeFiles/Processor.dir/main.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/main.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/main.cpp
CMakeFiles/Processor.dir/main.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Processor.dir/main.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/main.cpp.obj -MF CMakeFiles\Processor.dir\main.cpp.obj.d -o CMakeFiles\Processor.dir\main.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\main.cpp

CMakeFiles/Processor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/main.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\main.cpp > CMakeFiles\Processor.dir\main.cpp.i

CMakeFiles/Processor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/main.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\main.cpp -o CMakeFiles\Processor.dir\main.cpp.s

CMakeFiles/Processor.dir/image_adjustments.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_adjustments.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_adjustments.cpp
CMakeFiles/Processor.dir/image_adjustments.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Processor.dir/image_adjustments.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_adjustments.cpp.obj -MF CMakeFiles\Processor.dir\image_adjustments.cpp.obj.d -o CMakeFiles\Processor.dir\image_adjustments.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_adjustments.cpp

CMakeFiles/Processor.dir/image_adjustments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_adjustments.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_adjustments.cpp > CMakeFiles\Processor.dir\image_adjustments.cpp.i

CMakeFiles/Processor.dir/image_adjustments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_adjustments.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_adjustments.cpp -o CMakeFiles\Processor.dir\image_adjustments.cpp.s

CMakeFiles/Processor.dir/image_flip.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_flip.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_flip.cpp
CMakeFiles/Processor.dir/image_flip.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Processor.dir/image_flip.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_flip.cpp.obj -MF CMakeFiles\Processor.dir\image_flip.cpp.obj.d -o CMakeFiles\Processor.dir\image_flip.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_flip.cpp

CMakeFiles/Processor.dir/image_flip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_flip.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_flip.cpp > CMakeFiles\Processor.dir\image_flip.cpp.i

CMakeFiles/Processor.dir/image_flip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_flip.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_flip.cpp -o CMakeFiles\Processor.dir\image_flip.cpp.s

CMakeFiles/Processor.dir/image_filter.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_filter.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_filter.cpp
CMakeFiles/Processor.dir/image_filter.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Processor.dir/image_filter.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_filter.cpp.obj -MF CMakeFiles\Processor.dir\image_filter.cpp.obj.d -o CMakeFiles\Processor.dir\image_filter.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_filter.cpp

CMakeFiles/Processor.dir/image_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_filter.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_filter.cpp > CMakeFiles\Processor.dir\image_filter.cpp.i

CMakeFiles/Processor.dir/image_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_filter.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_filter.cpp -o CMakeFiles\Processor.dir\image_filter.cpp.s

CMakeFiles/Processor.dir/image_comparison.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_comparison.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_comparison.cpp
CMakeFiles/Processor.dir/image_comparison.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Processor.dir/image_comparison.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_comparison.cpp.obj -MF CMakeFiles\Processor.dir\image_comparison.cpp.obj.d -o CMakeFiles\Processor.dir\image_comparison.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_comparison.cpp

CMakeFiles/Processor.dir/image_comparison.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_comparison.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_comparison.cpp > CMakeFiles\Processor.dir\image_comparison.cpp.i

CMakeFiles/Processor.dir/image_comparison.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_comparison.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_comparison.cpp -o CMakeFiles\Processor.dir\image_comparison.cpp.s

CMakeFiles/Processor.dir/image_characteristics.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_characteristics.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_characteristics.cpp
CMakeFiles/Processor.dir/image_characteristics.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Processor.dir/image_characteristics.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_characteristics.cpp.obj -MF CMakeFiles\Processor.dir\image_characteristics.cpp.obj.d -o CMakeFiles\Processor.dir\image_characteristics.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_characteristics.cpp

CMakeFiles/Processor.dir/image_characteristics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_characteristics.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_characteristics.cpp > CMakeFiles\Processor.dir\image_characteristics.cpp.i

CMakeFiles/Processor.dir/image_characteristics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_characteristics.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_characteristics.cpp -o CMakeFiles\Processor.dir\image_characteristics.cpp.s

CMakeFiles/Processor.dir/image_histogram.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_histogram.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_histogram.cpp
CMakeFiles/Processor.dir/image_histogram.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Processor.dir/image_histogram.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_histogram.cpp.obj -MF CMakeFiles\Processor.dir\image_histogram.cpp.obj.d -o CMakeFiles\Processor.dir\image_histogram.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_histogram.cpp

CMakeFiles/Processor.dir/image_histogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_histogram.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_histogram.cpp > CMakeFiles\Processor.dir\image_histogram.cpp.i

CMakeFiles/Processor.dir/image_histogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_histogram.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_histogram.cpp -o CMakeFiles\Processor.dir\image_histogram.cpp.s

CMakeFiles/Processor.dir/image_morphing.cpp.obj: CMakeFiles/Processor.dir/flags.make
CMakeFiles/Processor.dir/image_morphing.cpp.obj: C:/Users/piotr/Desktop/Image-Processing/Processor/image_morphing.cpp
CMakeFiles/Processor.dir/image_morphing.cpp.obj: CMakeFiles/Processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Processor.dir/image_morphing.cpp.obj"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Processor.dir/image_morphing.cpp.obj -MF CMakeFiles\Processor.dir\image_morphing.cpp.obj.d -o CMakeFiles\Processor.dir\image_morphing.cpp.obj -c C:\Users\piotr\Desktop\Image-Processing\Processor\image_morphing.cpp

CMakeFiles/Processor.dir/image_morphing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Processor.dir/image_morphing.cpp.i"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piotr\Desktop\Image-Processing\Processor\image_morphing.cpp > CMakeFiles\Processor.dir\image_morphing.cpp.i

CMakeFiles/Processor.dir/image_morphing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Processor.dir/image_morphing.cpp.s"
	C:\Users\piotr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piotr\Desktop\Image-Processing\Processor\image_morphing.cpp -o CMakeFiles\Processor.dir\image_morphing.cpp.s

# Object files for target Processor
Processor_OBJECTS = \
"CMakeFiles/Processor.dir/main.cpp.obj" \
"CMakeFiles/Processor.dir/image_adjustments.cpp.obj" \
"CMakeFiles/Processor.dir/image_flip.cpp.obj" \
"CMakeFiles/Processor.dir/image_filter.cpp.obj" \
"CMakeFiles/Processor.dir/image_comparison.cpp.obj" \
"CMakeFiles/Processor.dir/image_characteristics.cpp.obj" \
"CMakeFiles/Processor.dir/image_histogram.cpp.obj" \
"CMakeFiles/Processor.dir/image_morphing.cpp.obj"

# External object files for target Processor
Processor_EXTERNAL_OBJECTS =

Processor.exe: CMakeFiles/Processor.dir/main.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_adjustments.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_flip.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_filter.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_comparison.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_characteristics.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_histogram.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/image_morphing.cpp.obj
Processor.exe: CMakeFiles/Processor.dir/build.make
Processor.exe: CMakeFiles/Processor.dir/linklibs.rsp
Processor.exe: CMakeFiles/Processor.dir/objects1.rsp
Processor.exe: CMakeFiles/Processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Processor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Processor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Processor.dir/build: Processor.exe
.PHONY : CMakeFiles/Processor.dir/build

CMakeFiles/Processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Processor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Processor.dir/clean

CMakeFiles/Processor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\piotr\Desktop\Image-Processing\Processor C:\Users\piotr\Desktop\Image-Processing\Processor C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug C:\Users\piotr\Desktop\Image-Processing\Processor\cmake-build-debug\CMakeFiles\Processor.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Processor.dir/depend

