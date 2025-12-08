#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "raygui.h"
#include "ui/text.hpp"

namespace game {
class GameOver : public GameNode {
  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  void start() override;
  void render() override;
};
} // namespace game
