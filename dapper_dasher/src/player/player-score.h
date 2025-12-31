#pragma once

#include "database/key-value-repository.h"
#include "timer/schedule-service.h"
#include <string>
#include <cstdint>

namespace game {
class PlayerScore {
private:
  int score;
  int highScore;
  const std::string highScoreKey = config::PLAYER_SERVICE_DATABASE_HIGHSCORE_KEY;
  const int scoreInterval = config::PLAYER_SERVICE_SCORE_INTERVAL;

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
