#pragma once

#include "async/async-pointer.h"
#include "config/config.h"
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
  PlayerScore() {
    emitter->on("game/start", [this](Event event) { onStart(); });
    emitter->on("game/update", [this](Event event) { onUpdate(); });
    emitter->on("game/stop", [this](Event event) { onStop(); });
  }

  void onStart() {
    score = 0;
    loadHighScoreScore();
    log->info("(player-score) Started.");
  }

  void onUpdate() {
    if (!gameState->isRunning()) {
      return;
    }
    if (!scoreTimer.isActive()) {
      score += 1;
      if (score > highScore) {
        setHighScore(score);
        log->info("(player-score) New highscore.");
      }
      scoreTimer.start();
    }
  }

  void onStop() {
    log->info(
        fmt::format("(player-score) Persisted a highscore of {}.", highScore));
    log->info("(player-score) Stopped.");
  }

  void loadHighScoreScore() {
    std::string highScoreAsString = "0";
    database->get(highScoreKey, &highScoreAsString);
    setHighScore(std::stoi(highScoreAsString));
    log->info(
        fmt::format("(player-score) Restored a highscore of {}.", highScore));
  }

  void setScore(int score) { this->score = score; }
  int getScore() { return score; }

  void setHighScore(int highScore) {
    this->highScore = highScore;
    database->set(highScoreKey, std::to_string(highScore));
  }
  int getHighScore() { return highScore; }
};
} // namespace game
