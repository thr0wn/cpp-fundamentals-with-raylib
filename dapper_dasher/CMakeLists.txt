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
set(RAYLIB_VERSION 5.0)
set(RAYGUI_VERSION 4.0)
set(FMT_VERSION 9.1.0)
set(LEVELDB_VERSION 1.23)

# compile options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU") 
  # raygui has a lot of warnings of -Wenum-compare
  add_compile_options(-Wno-enum-compare)
  # leveldb uses a version gtest that throws this error
  add_compile_options(-Wno-error=maybe-uninitialized)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
endif()

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

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG ${FMT_VERSION}
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

# remove some not used build targets from leveldb
option(LEVELDB_BUILD_TESTS "Build LevelDB's unit tests" OFF)
option(LEVELDB_BUILD_BENCHMARKS "Build LevelDB's benchmarks" OFF)
option(LEVELDB_INSTALL "Install LevelDB's header and library" OFF)

FetchContent_Declare(
    leveldb
    GIT_REPOSITORY https://github.com/google/leveldb
    GIT_TAG ${LEVELDB_VERSION}
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(leveldb)

add_subdirectory(src)
