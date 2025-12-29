#pragma once

#include "database/key-value-repository.h"
#include "timer/schedule-service.h"
#include <string>
#include <cstdint>

namespace game {
class PlayerService {
private:
  std::uint32_t score;
  std::uint32_t highScore;
  const std::string highScoreKey = config::PLAYER_SERVICE_DATABASE_HIGHSCORE_KEY;
  const int scoreInterval = config::PLAYER_SERVICE_SCORE_INTERVAL;
  
public:
  PlayerService();

  void onStart();
  void onStop();

  void loadHighScoreScore();

  std::uint32_t getScore();  
  std::uint32_t getHighScore();  
};

extern std::unique_ptr<PlayerService> playerService;
}
