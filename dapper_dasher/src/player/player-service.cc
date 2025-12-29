#include "player/player-service.h"

namespace game {
PlayerService::PlayerService() {
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/stop", [this](Event event) { onStop(); });
}

void PlayerService::onStart() {
  // score
  score = 0;
  scheduleService->repeat(
      [this] {
        if (!gameService->isRunning()) {
          return;
        }
        score++;
        if (score > highScore) {
          highScore = score;
          keyValueRepository->set(highScoreKey, std::to_string(highScore));
          logService->info("(player-service) Player service new highscore.");
        }
      },
      scoreInterval);
  loadHighScoreScore();
  logService->info("(player-service) Player Service started.");
}

void PlayerService::onStop() {
  keyValueRepository->set(highScoreKey, std::to_string(highScore));
  logService->info(
      fmt::format("(player-service) Persisted a highscore of {}.", highScore));
  logService->info("(player-service) Player Service stopped.");
}

void PlayerService::loadHighScoreScore() {
  std::string highscoreAsString = "0";
  keyValueRepository->get(highScoreKey, &highscoreAsString);
  highScore = std::stoi(highscoreAsString);
  logService->info(
      fmt::format("(player-service) Restored a highscore of {}.", highScore));
}

std::uint32_t PlayerService::getScore() { return score; }

std::uint32_t PlayerService::getHighScore() { return highScore; }

std::unique_ptr<PlayerService> playerService;
} // namespace game
