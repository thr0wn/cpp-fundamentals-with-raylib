#pragma once
#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-service.h"
#include "raygui.h"
#include "ui/text.h"
#include <string>

namespace game {
class Pause {
  Text textResume{config::PAUSE_TEXT_RESUME};
  bool textResumeIsPressed = false;

  Text textRestart{config::PAUSE_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::PAUSE_TEXT_QUIT};
  bool textQuitIsPressed = false;

  GameState *gameState;
  
public:
  Pause();

  void onInit();
  void onUpdate();
  void onRender();
};
} // namespace game
