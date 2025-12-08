#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-service.h"
#include "raygui.h"
#include "ui/text.h"

namespace game {
class GameOver : public GameNode {
  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  GameOver();
  
  void start() override;
  void render() override;
};
} // namespace game
