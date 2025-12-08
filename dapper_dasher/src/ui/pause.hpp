#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "raygui.h"
#include "ui/text.hpp"
#include <string>

namespace game {
class Pause : public GameNode {
  Text textResume{config::PAUSE_TEXT_RESUME};
  bool textResumeIsPressed = false;

  Text textRestart{config::PAUSE_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::PAUSE_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  void start() override;
  void update() override;
  void render() override;
};
} // namespace game
