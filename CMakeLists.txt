# Set the cmake versions while accounting for an old MSVC CMake bug:
# https://cliutils.gitlab.io/modern-cmake/chapters/basics.html
cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.23)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.23)
endif()

# Create project "cpp-study"
project(cpp-study VERSION 1.0
        DESCRIPTION "Collection of programs from studying C++ up to c++17."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Only do these if this is the main project, and not if it is included through add_subdirectory.
# Based on: https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/CMakeLists.txt
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# FetchContent_MakeAvailable was not added until CMake 3.14; use our shim
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
find_package(Boost REQUIRED)
# Adds Boost::boost

# Formatting library
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)
# Adds fmt::fmt

# 
#set(CPPSTUDY_BUILD_DIR build)

# Compile every physisical component's objects and executables into the root's 'build' directory.
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build )

# Compile library objects and executables into the root's 'lib' directory.
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs )

# The source library code is here.
add_subdirectory(src)

# The executable code is here
# add_subdirectory(build)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()



#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# Add main.cpp file of project root directory as source file
# set(SOURCE_FILES src/hello_world.cpp)

# https://stackoverflow.com/questions/23995019/what-is-the-modern-method-for-setting-general-compile-flags-in-cmake
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1

# Add executable target with source files listed in SOURCE_FILES variable
#add_executable(hello_world ${SOURCE_FILES})

# Using 'target_compile_features' versus 'target_compile_options'.
# https://stackoverflow.com/questions/71855535/cmake-target-compile-options-vs-target-compile-definitions


########
########
########

# add_executable(hello_world src/cppstudy/hello_world.cpp)

#target_compile_options(hello_world PRIVATE "$<$<CONFIG:Debug>:--my-flag>")

#set(MY_DEBUG_OPTIONS, -Wall)

#target_compile_options(hello_world PUBLIC "$<$<CONFIG:DEBUG>:${MY_DEBUG_OPTIONS}>")
#target_compile_options(hello_world PUBLIC "$<$<CONFIG:RELEASE>:${MY_RELEASE_OPTIONS}>")