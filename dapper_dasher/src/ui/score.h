#pragma once
#include "async/async-pointer.h"
#include "log/log.h"
#include "config/config.h"
#include "game/game-state.h"
#include "player/player-score.h"
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

  GameState *gameState = AsyncPointer::get<GameState>();
  PlayerScore *playerScore = AsyncPointer::get<PlayerScore>();
  Log *log = AsyncPointer::get<Log>();  

public:
  Score();

  void onStart();
  void onRender();
};
} // namespace game
