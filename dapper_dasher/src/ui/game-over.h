#pragma once
#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "async/async-pointer.h"
#include "log/log.h"
#include "raygui.h"
#include "ui/text.h"

namespace game {
class GameOver {
  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();  

public:
  GameOver();

  void onInit();
  void onRender();
};
} // namespace game
