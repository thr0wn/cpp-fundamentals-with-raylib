#pragma once

#include "config/config.h"
#include "async/async-pointer.h"
#include "database/database.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "timer/timer.h"
#include <cstdint>
#include <map>
#include <string>

namespace game {
class PlayerScore {
private:
  int score;
  int highScore;
  const std::string highScoreKey =
      config::PLAYER_SERVICE_DATABASE_HIGHSCORE_KEY;
  Timer scoreTimer{config::PLAYER_SERVICE_SCORE_INTERVAL};

  Emitter *emitter = AsyncPointer::get<Emitter>();  
  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();
  Database *database = AsyncPointer::get<Database>();

public:
  PlayerScore();

  void onStart();
  void onUpdate();
  void onStop();

  void loadHighScoreScore();

  void setScore(int score);
  int getScore();
  void setHighScore(int highScore);
  int getHighScore();
};
} // namespace game
