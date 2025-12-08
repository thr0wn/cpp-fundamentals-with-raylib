#pragma once
#include "config/config.hpp"
#include "database/database-service.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "raygui.h"
#include "ui/text.hpp"
#include <fmt/format.h>
#include <string>

namespace game {
class Score : public GameNode {
  int score;
  int highScore;
  const std::string highScoreKey = config::SCORE_DATABASE_HIGHSCORE_KEY;
  const int scoreInterval = config::SCORE_INTERVAL;

  Text textScore{config::SCORE_TEXT_SCORE};
  bool textScoreIsPressed = false;

  Text textHighScore{config::SCORE_TEXT_HIGH_SCORE};
  bool textHighScoreIsPressed = false;

  Text textPressSpace{config::SCORE_TEXT_PRESS_SPACE};
  bool textPressSpaceIsPressed = false;

public:
  Score();
  
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
  ;
};
} // namespace game
