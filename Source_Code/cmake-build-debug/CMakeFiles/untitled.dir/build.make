# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/jojo/CLionProjects/WebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/jojo/CLionProjects/WebServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/main.cpp.o -c /usr/jojo/CLionProjects/WebServer/main.cpp

CMakeFiles/untitled.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/WebServer/main.cpp > CMakeFiles/untitled.dir/main.cpp.i

CMakeFiles/untitled.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/WebServer/main.cpp -o CMakeFiles/untitled.dir/main.cpp.s

CMakeFiles/untitled.dir/util.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/util.c.o: ../util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled.dir/util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/util.c.o   -c /usr/jojo/CLionProjects/WebServer/util.c

CMakeFiles/untitled.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/util.c > CMakeFiles/untitled.dir/util.c.i

CMakeFiles/untitled.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/util.c -o CMakeFiles/untitled.dir/util.c.s

CMakeFiles/untitled.dir/epoll.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/epoll.c.o: ../epoll.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled.dir/epoll.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/epoll.c.o   -c /usr/jojo/CLionProjects/WebServer/epoll.c

CMakeFiles/untitled.dir/epoll.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/epoll.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/epoll.c > CMakeFiles/untitled.dir/epoll.c.i

CMakeFiles/untitled.dir/epoll.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/epoll.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/epoll.c -o CMakeFiles/untitled.dir/epoll.c.s

CMakeFiles/untitled.dir/http.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/http.c.o: ../http.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled.dir/http.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/http.c.o   -c /usr/jojo/CLionProjects/WebServer/http.c

CMakeFiles/untitled.dir/http.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/http.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/http.c > CMakeFiles/untitled.dir/http.c.i

CMakeFiles/untitled.dir/http.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/http.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/http.c -o CMakeFiles/untitled.dir/http.c.s

CMakeFiles/untitled.dir/http_parse.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/http_parse.cpp.o: ../http_parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled.dir/http_parse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/http_parse.cpp.o -c /usr/jojo/CLionProjects/WebServer/http_parse.cpp

CMakeFiles/untitled.dir/http_parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/http_parse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/jojo/CLionProjects/WebServer/http_parse.cpp > CMakeFiles/untitled.dir/http_parse.cpp.i

CMakeFiles/untitled.dir/http_parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/http_parse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/jojo/CLionProjects/WebServer/http_parse.cpp -o CMakeFiles/untitled.dir/http_parse.cpp.s

CMakeFiles/untitled.dir/http_request.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/http_request.c.o: ../http_request.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/untitled.dir/http_request.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/http_request.c.o   -c /usr/jojo/CLionProjects/WebServer/http_request.c

CMakeFiles/untitled.dir/http_request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/http_request.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/http_request.c > CMakeFiles/untitled.dir/http_request.c.i

CMakeFiles/untitled.dir/http_request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/http_request.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/http_request.c -o CMakeFiles/untitled.dir/http_request.c.s

CMakeFiles/untitled.dir/timer.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/timer.c.o: ../timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/untitled.dir/timer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/timer.c.o   -c /usr/jojo/CLionProjects/WebServer/timer.c

CMakeFiles/untitled.dir/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/timer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/timer.c > CMakeFiles/untitled.dir/timer.c.i

CMakeFiles/untitled.dir/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/timer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/timer.c -o CMakeFiles/untitled.dir/timer.c.s

CMakeFiles/untitled.dir/threadpool.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/threadpool.c.o: ../threadpool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/untitled.dir/threadpool.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/threadpool.c.o   -c /usr/jojo/CLionProjects/WebServer/threadpool.c

CMakeFiles/untitled.dir/threadpool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/threadpool.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/jojo/CLionProjects/WebServer/threadpool.c > CMakeFiles/untitled.dir/threadpool.c.i

CMakeFiles/untitled.dir/threadpool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/threadpool.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/jojo/CLionProjects/WebServer/threadpool.c -o CMakeFiles/untitled.dir/threadpool.c.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.cpp.o" \
"CMakeFiles/untitled.dir/util.c.o" \
"CMakeFiles/untitled.dir/epoll.c.o" \
"CMakeFiles/untitled.dir/http.c.o" \
"CMakeFiles/untitled.dir/http_parse.cpp.o" \
"CMakeFiles/untitled.dir/http_request.c.o" \
"CMakeFiles/untitled.dir/timer.c.o" \
"CMakeFiles/untitled.dir/threadpool.c.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/main.cpp.o
untitled: CMakeFiles/untitled.dir/util.c.o
untitled: CMakeFiles/untitled.dir/epoll.c.o
untitled: CMakeFiles/untitled.dir/http.c.o
untitled: CMakeFiles/untitled.dir/http_parse.cpp.o
untitled: CMakeFiles/untitled.dir/http_request.c.o
untitled: CMakeFiles/untitled.dir/timer.c.o
untitled: CMakeFiles/untitled.dir/threadpool.c.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /usr/jojo/CLionProjects/WebServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/jojo/CLionProjects/WebServer /usr/jojo/CLionProjects/WebServer /usr/jojo/CLionProjects/WebServer/cmake-build-debug /usr/jojo/CLionProjects/WebServer/cmake-build-debug /usr/jojo/CLionProjects/WebServer/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

