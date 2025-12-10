#pragma once
#include "config/config.h"
#include "database/database-service.h"
#include "game/game-node.h"
#include "game/game-service.h"
#include "raygui.h"
#include "ui/text.h"
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
  void restart() override;
  void update() override;
  void render() override;
  void stop() override;
  ;
};
} // namespace game
