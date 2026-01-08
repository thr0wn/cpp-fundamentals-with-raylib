#include "player/player-score.h"

namespace game {
PlayerScore::PlayerScore() {
  emitter->on("game/start", [this](Event event) { onStart(); });
  emitter->on("game/update", [this](Event event) { onUpdate(); });
  emitter->on("game/stop", [this](Event event) { onStop(); });
}

void PlayerScore::onStart() {
  score = 0;
  loadHighScoreScore();
  log->info("(player-score) Started.");
}

void PlayerScore::onUpdate() {
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

void PlayerScore::onStop() {
  log->info(
      fmt::format("(player-score) Persisted a highscore of {}.", highScore));
  log->info("(player-score) Stopped.");
}

void PlayerScore::loadHighScoreScore() {
  std::string highScoreAsString = "0";
  database->get(highScoreKey, &highScoreAsString);
  setHighScore(std::stoi(highScoreAsString));
  log->info(
      fmt::format("(player-score) Restored a highscore of {}.", highScore));
}

void PlayerScore::setScore(int score) { this->score = score; }
int PlayerScore::getScore() { return score; }

void PlayerScore::setHighScore(int highScore) {
  this->highScore = highScore;
  database->set(highScoreKey, std::to_string(highScore));
}
int PlayerScore::getHighScore() { return highScore; }

} // namespace game
