#include "player/player-score.h"

namespace game {
PlayerScore::PlayerScore() {
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/stop", [this](Event event) { onStop(); });
}

void PlayerScore::onStart() {
  // score
  setScore(0);
  scheduleService->repeat(
      [this] {
        if (!gameService->isRunning()) {
          return;
        }
        setScore(score + 1);
        if (score > highScore) {
          setHighScore(score);
          logService->info("(player-score) Player service new highscore.");
        }
      },
      scoreInterval);
  loadHighScoreScore();
  logService->info("(player-score) Player Service started.");
}

void PlayerScore::onStop() {
  logService->info(
      fmt::format("(player-score) Persisted a highscore of {}.", highScore));
  logService->info("(player-score) Player Service stopped.");
}

void PlayerScore::loadHighScoreScore() {
  std::string highscoreAsString = "0";
  keyValueRepository->get(highScoreKey, &highscoreAsString);
  setHighScore(std::stoi(highscoreAsString));
  logService->info(
      fmt::format("(player-score) Restored a highscore of {}.", highScore));
}

void PlayerScore::setScore(int score) {
  this->score = score;
  Event scoreChangeEvent{"player/score", score};
  gameEmitter->emit(scoreChangeEvent);
}
int PlayerScore::getScore() { return score; }

void PlayerScore::setHighScore(int highScore) {
  this->highScore = highScore;
  keyValueRepository->set(highScoreKey, std::to_string(highScore));
  Event highScoreChangeEvent{"player/highScore", highScore};
  gameEmitter->emit(highScoreChangeEvent);
}
int PlayerScore::getHighScore() { return highScore; }

} // namespace game
