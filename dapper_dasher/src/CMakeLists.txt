# glob select cpps and hpps
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.hpp)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

# enable #include without relative path
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/player")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/timer")

# include config.hpp
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/config")
add_subdirectory(config)
