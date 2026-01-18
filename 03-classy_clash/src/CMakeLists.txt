add_subdirectory(config)

# library setup
# ----------------------------------------------------------------------------------------
set(LIBRARY_SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/database/database.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/event/event.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/event/emitter.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/event/listener.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-node.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-state.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/geometry/vector.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/geometry/geometry.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/log/log.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/player/player.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/texture/texture-loader.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/texture/tile.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/texture/tile-animation.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/timer/timer.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/ui/text.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/start.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/pause.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/game-over.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/world/world.cc"
)
set(LIBRARY_HEADER_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/async/async-pointer.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/database/database.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/event/event.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/event/emitter.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/event/listener.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-state.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game-node.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/game/game.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/geometry/vector.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/geometry/geometry.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/log/log.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/player/player.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/texture/texture-loader.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/texture/tile.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/texture/tile-animation.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/timer/timer.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/ui/ui.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/text.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/start.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/pause.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/ui/game-over.h"

  "${CMAKE_CURRENT_SOURCE_DIR}/world/world.h"
)
add_library(${LIBRARY_NAME} STATIC
  ${LIBRARY_SOURCE_FILES}
  ${LIBRARY_HEADER_FILES}
)
target_link_libraries(${LIBRARY_NAME} PUBLIC
  raygui
  raylib
  fmt::fmt
)

# enable #include without relative path
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_BINARY_DIR}")

# executable setup
# ----------------------------------------------------------------------------------------
add_executable(${EXECUTABLE_NAME}
  "${CMAKE_SOURCE_DIR}/src/main.cc"
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

# executable_started (with game alredy started) setup
# ----------------------------------------------------------------------------------------
add_executable(${EXECUTABLE_STARTED_NAME}
  "${CMAKE_SOURCE_DIR}/src/main-started.cc"
)
target_link_libraries(${EXECUTABLE_STARTED_NAME} PUBLIC
  ${LIBRARY_NAME}
)

# output dir
set_target_properties(${EXECUTABLE_STARTED_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fast-debug
)
