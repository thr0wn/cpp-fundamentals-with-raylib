#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-service.h"
#include "raygui.h"
#include "ui/text.h"
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
  Pause();
  
  void start() override;
  void update() override;
  void render() override;
};
} // namespace game
