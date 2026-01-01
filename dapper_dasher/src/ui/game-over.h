#pragma once
#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "raygui.h"
#include "ui/text.h"

namespace game {
class GameOver {
  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

  GameState *gameState;

public:
  GameOver();

  void onInit();
  void onRender();
};
} // namespace game
