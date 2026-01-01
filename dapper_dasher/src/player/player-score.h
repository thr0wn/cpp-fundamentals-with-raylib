#pragma once

#include "config/config.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "timer/schedule-service.h"
#include <string>
#include <cstdint>
#include <map>

namespace game {
class PlayerScore {
private:
  int score;
  int highScore;
  const std::string highScoreKey = config::PLAYER_SERVICE_DATABASE_HIGHSCORE_KEY;
  const int scoreInterval = config::PLAYER_SERVICE_SCORE_INTERVAL;

  GameState *gameState;

public:
  PlayerScore();

  void onStart();
  void onStop();

  void loadHighScoreScore();

  void setScore(int score);  
  int getScore();  
  void setHighScore(int highScore);  
  int getHighScore();  
};
}
