cmake_minimum_required(VERSION 3.22.0)

project(dapper_dasher)
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# library and executable name definitions
set(LIBRARY_NAME game-lib)
set(EXECUTABLE_NAME exe)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.5)
set(RAYGUI_VERSION 4.0)

# fetch and declare content
include(FetchContent)
FetchContent_Declare(
  raylib
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(raylib)
FetchContent_Declare(
  raygui
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL https://github.com/raysan5/raygui/archive/refs/tags/${RAYGUI_VERSION}.tar.gz
  FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(raygui)
add_subdirectory(${raygui_SOURCE_DIR}/projects/CMake)

add_subdirectory(src)
