#pragma once
#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-service.h"
#include "ui/text.h"
#include <string>

namespace game {
class Start {
  Text textNewGame{config::START_TEXT_NEW_GAME};
  bool textNewGameIsPressed = false;

  Text textQuit{config::START_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  Start();

  void onInit();
  void onRender();
};
} // namespace game
