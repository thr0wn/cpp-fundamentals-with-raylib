#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include <string>
#include "raygui.h"

class Pause : public GameNode {
  const std::string textResume = config::PAUSE_TEXT_RESUME;
  Rectangle textResumeRec;
  bool textResumeIsPressed = false;

  const std::string textRestart = config::PAUSE_TEXT_RESTART;
  Rectangle textRestartRec;
  bool textRestartIsPressed = false;    

  const std::string textQuit = config::PAUSE_TEXT_QUIT;
  Rectangle textQuitRec;
  bool textQuitIsPressed = false;

public:
  void start() override;
  void update() override;
  void render() override;
};
