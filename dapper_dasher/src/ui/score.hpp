#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include <string>
#include <fmt/format.h>
#include "raygui.h"

class Score : public GameNode {
  int score;
  int highScore;
  const int scoreInterval = config::SCORE_INTERVAL;
  
  const std::string textScore = config::SCORE_TEXT_SCORE;
  Rectangle textScoreRec;
  bool textScoreIsPressed = false;

  const std::string textHighScore = config::SCORE_TEXT_HIGH_SCORE;
  Rectangle textHighScoreRec;
  bool textHighScoreIsPressed = false;

  const std::string textPressSpace = config::SCORE_TEXT_PRESS_SPACE;
  Rectangle textPressSpaceRec;
  bool textPressSpaceIsPressed = false;

public:
  void start() override;
  void update() override;
  void render() override;
};
