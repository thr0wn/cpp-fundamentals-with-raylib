#pragma once
#include "async/async-pointer.h"
#include "log/log.h"
#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "ui/text.h"
#include <string>

namespace game {
class Start {
  Text textNewGame{config::START_TEXT_NEW_GAME};
  bool textNewGameIsPressed = false;

  Text textQuit{config::START_TEXT_QUIT};
  bool textQuitIsPressed = false;

  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();
public:
  Start();

  void onInit();
  void onRender();
};
} // namespace game
