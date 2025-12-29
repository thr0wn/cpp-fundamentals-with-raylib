#pragma once
#include "config/config.h"
#include "player/player-service.h"
#include "database/key-value-repository.h"
#include "game/game-service.h"
#include "raygui.h"
#include "ui/text.h"
#include <fmt/format.h>
#include <string>

namespace game {
class Score {
  Text textScore{config::SCORE_TEXT_SCORE};
  bool textScoreIsPressed = false;

  Text textHighScore{config::SCORE_TEXT_HIGH_SCORE};
  bool textHighScoreIsPressed = false;

  Text textPressSpace{config::SCORE_TEXT_PRESS_SPACE};
  bool textPressSpaceIsPressed = false;

public:
  Score();
  
  void onStart();
  void onRender();

};
} // namespace game
