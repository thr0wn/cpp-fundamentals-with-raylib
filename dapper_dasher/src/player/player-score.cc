#include "player/player-score.h"

namespace game {
PlayerScore::PlayerScore() {
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/stop", [this](Event event) { onStop(); });
}

void PlayerScore::onStart() {
  // Pass reference to the state  
  gameEmitter->emit({"player/score", &score});
  gameEmitter->emit({"player/highScore", &highScore});
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
          gameEmitter->emit(
              {"log/info", std::string("(player-score) New highscore.")});
        }
      },
      scoreInterval);
  loadHighScoreScore();
  gameEmitter->emit({"log/info", std::string("(player-score) Started.")});
}

void PlayerScore::onStop() {
  gameEmitter->emit(
      {"log/info",
       std::string(fmt::format("(player-score) Persisted a highscore of {}.",
                               highScore))});
  gameEmitter->emit({"log/info", std::string("(player-score) Stopped.")});
}

void PlayerScore::loadHighScoreScore() {
  std::string highScoreAsString = "0";
  gameEmitter->emit({"database/get", (std::pair<std::string, std::string *>){
                                         highScoreKey, &highScoreAsString}});
  setHighScore(std::stoi(highScoreAsString));
  gameEmitter->emit(
      {"log/info",
       std::string(fmt::format("(player-score) Restored a highscore of {}.",
                               highScore))});
}

void PlayerScore::setScore(int score) {
  this->score = score;
}
int PlayerScore::getScore() { return score; }

void PlayerScore::setHighScore(int highScore) {
  this->highScore = highScore;
  gameEmitter->emit(
      {"database/set", (std::pair<std::string, std::string>){
                           highScoreKey, std::to_string(highScore)}});
}
int PlayerScore::getHighScore() { return highScore; }

} // namespace game
