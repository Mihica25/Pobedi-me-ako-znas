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
CMAKE_SOURCE_DIR = /home/user/Desktop/pobedi-me-ako-znas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Desktop/pobedi-me-ako-znas/build

# Utility rule file for ServerApplication_autogen.

# Include the progress variables for this target.
include server/server/CMakeFiles/ServerApplication_autogen.dir/progress.make

server/server/CMakeFiles/ServerApplication_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/user/Desktop/pobedi-me-ako-znas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ServerApplication"
	cd /home/user/Desktop/pobedi-me-ako-znas/build/server/server && /usr/bin/cmake -E cmake_autogen /home/user/Desktop/pobedi-me-ako-znas/build/server/server/CMakeFiles/ServerApplication_autogen.dir/AutogenInfo.json ""

ServerApplication_autogen: server/server/CMakeFiles/ServerApplication_autogen
ServerApplication_autogen: server/server/CMakeFiles/ServerApplication_autogen.dir/build.make

.PHONY : ServerApplication_autogen

# Rule to build all files generated by this target.
server/server/CMakeFiles/ServerApplication_autogen.dir/build: ServerApplication_autogen

.PHONY : server/server/CMakeFiles/ServerApplication_autogen.dir/build

server/server/CMakeFiles/ServerApplication_autogen.dir/clean:
	cd /home/user/Desktop/pobedi-me-ako-znas/build/server/server && $(CMAKE_COMMAND) -P CMakeFiles/ServerApplication_autogen.dir/cmake_clean.cmake
.PHONY : server/server/CMakeFiles/ServerApplication_autogen.dir/clean

server/server/CMakeFiles/ServerApplication_autogen.dir/depend:
	cd /home/user/Desktop/pobedi-me-ako-znas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Desktop/pobedi-me-ako-znas /home/user/Desktop/pobedi-me-ako-znas/server/server /home/user/Desktop/pobedi-me-ako-znas/build /home/user/Desktop/pobedi-me-ako-znas/build/server/server /home/user/Desktop/pobedi-me-ako-znas/build/server/server/CMakeFiles/ServerApplication_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/server/CMakeFiles/ServerApplication_autogen.dir/depend
