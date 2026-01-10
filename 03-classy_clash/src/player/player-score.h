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
  int _score;
  int _highScore;
  const std::string _highScoreKey =
      config::PLAYER_SERVICE_DATABASE_HIGHSCORE_KEY;
  Timer _scoreTimer{config::PLAYER_SERVICE_SCORE_INTERVAL};

  Emitter *_emitter = AsyncPointer::get<Emitter>();  
  GameState *_gameState = AsyncPointer::get<GameState>();
  Log *_log = AsyncPointer::get<Log>();
  Database *_database = AsyncPointer::get<Database>();

  void loadHighScoreScore();
  void setHighScore(const int &highScore);  
public:
  PlayerScore();

  void onStart();
  void onUpdate();
  void onStop();

  const int &score();
  const int &highScore();
};
} // namespace game
