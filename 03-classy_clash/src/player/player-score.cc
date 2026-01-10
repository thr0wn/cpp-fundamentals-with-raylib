#include "player/player-score.h"

namespace game {
PlayerScore::PlayerScore() {
  _emitter->on("game/start", [this](Event event) { onStart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/stop", [this](Event event) { onStop(); });
}

void PlayerScore::onStart() {
  _score = 0;
  loadHighScoreScore();
  _log->info("(player-score) Started.");
}

void PlayerScore::onUpdate() {
  if (!_gameState->running()) {
    return;    
  }
  if (!_scoreTimer.active()) {
    _score += 1;
    if (_score > _highScore) {
      setHighScore(_score);
      _log->info("(player-score) New highscore.");
    }
    _scoreTimer.start();
  }
}

void PlayerScore::onStop() {
  _log->info(
      fmt::format("(player-score) Persisted a highscore of {}.", _highScore));
  _log->info("(player-score) Stopped.");
}

void PlayerScore::loadHighScoreScore() {
  std::string highScoreAsString = "0";
  _database->get(_highScoreKey, &highScoreAsString);
  setHighScore(std::stoi(highScoreAsString));
  _log->info(
      fmt::format("(player-score) Restored a highscore of {}.", _highScore));
}

const int &PlayerScore::score() { return _score; }

void PlayerScore::setHighScore(const int &highScore) {
  this->_highScore = highScore;
  _database->set(_highScoreKey, std::to_string(highScore));
}
const int &PlayerScore::highScore() { return _highScore; }

} // namespace game
