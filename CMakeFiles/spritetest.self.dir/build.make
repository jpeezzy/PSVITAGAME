# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbreaker/gitProjects/samples/sdl2/spriteTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbreaker/gitProjects/samples/sdl2/spriteTest

# Utility rule file for spritetest.self.

# Include the progress variables for this target.
include CMakeFiles/spritetest.self.dir/progress.make

CMakeFiles/spritetest.self: spritetest.velf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/macbreaker/gitProjects/samples/sdl2/spriteTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating SELF spritetest.self"
	/usr/local/vitasdk/bin/vita-make-fself -c -s spritetest.velf spritetest.self

spritetest.velf: spritetest
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/macbreaker/gitProjects/samples/sdl2/spriteTest/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Converting to Sony ELF spritetest.velf"
	/usr/local/vitasdk/bin/vita-elf-create spritetest spritetest.velf

spritetest.self: CMakeFiles/spritetest.self
spritetest.self: spritetest.velf
spritetest.self: CMakeFiles/spritetest.self.dir/build.make

.PHONY : spritetest.self

# Rule to build all files generated by this target.
CMakeFiles/spritetest.self.dir/build: spritetest.self

.PHONY : CMakeFiles/spritetest.self.dir/build

CMakeFiles/spritetest.self.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spritetest.self.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spritetest.self.dir/clean

CMakeFiles/spritetest.self.dir/depend:
	cd /Users/macbreaker/gitProjects/samples/sdl2/spriteTest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbreaker/gitProjects/samples/sdl2/spriteTest /Users/macbreaker/gitProjects/samples/sdl2/spriteTest /Users/macbreaker/gitProjects/samples/sdl2/spriteTest /Users/macbreaker/gitProjects/samples/sdl2/spriteTest /Users/macbreaker/gitProjects/samples/sdl2/spriteTest/CMakeFiles/spritetest.self.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spritetest.self.dir/depend

