set(SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/player/player.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/timer/timer.cpp"
)
set(HEADER_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/common.hpp"
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

# enable #include without relative path
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/player")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/timer")

# include config.hpp
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/config")
add_subdirectory(config)
