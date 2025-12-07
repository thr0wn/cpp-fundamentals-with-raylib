#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "ui/text.hpp"
#include "raygui.h"

class GameOver : public GameNode {
  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  void start() override;
  void render() override;
};
