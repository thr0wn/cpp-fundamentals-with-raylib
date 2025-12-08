add_subdirectory(config)

# library setup
# ----------------------------------------------------------------------------------------
set(LIBRARY_SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-node.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-service.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/background/background.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/database/database-service.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/log/log-service.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/nebula/nebula.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/player/player.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/text.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/start.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/score.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/pause.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/game-over.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/timer/schedule-service.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/timer/timer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tile/tile-service.cpp"
)
set(LIBRARY_HEADER_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-state.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-node.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-service.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/database/database-service.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/log/log-service.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/background/background.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/nebula/nebula.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/player/player.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/text.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/start.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/score.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/pause.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/game-over.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/timer/schedule.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/timer/schedule-service.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tile/tile.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tile/tile-service.hpp"
)
add_library(${LIBRARY_NAME} STATIC
  ${LIBRARY_SOURCE_FILES}
  ${LIBRARY_HEADER_FILES}
)
target_link_libraries(${LIBRARY_NAME} PUBLIC
  raygui
  raylib
  fmt::fmt
  leveldb
)

# enable #include without relative path
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_BINARY_DIR}")

# executable setup
# ----------------------------------------------------------------------------------------
set(EXECUTABLE_SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/src/main.cpp"
)
add_executable(${EXECUTABLE_NAME}
  ${EXECUTABLE_SOURCE_FILES}
)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
  ${LIBRARY_NAME}
)

# output dir
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
)
# some debug property
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>)
# copy resources
add_custom_command(
  TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/resources
)
