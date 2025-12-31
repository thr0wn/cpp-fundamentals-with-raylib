#include "game/game-service.h"

namespace game {
GameService::GameService() {
  gameEmitter->on("game/init:before", [this](Event event) { onBeforeInit(); });
  gameEmitter->on("game/render:before",
                  [this](Event event) { onBeforeRender(); });
  gameEmitter->on("game/render:after",
                  [this](Event event) { onAfterRender(); });
  gameEmitter->on("game/deinit:after",
                  [this](Event event) { onAfterDeinit(); });
}

void GameService::init() {
  gameEmitter->emit("game/init", {{"before", true}, {"after", true}});
}

void GameService::update() {
  gameEmitter->emit("game/update",
                    {{"log", false}, {"before", true}, {"after", true}});
}

void GameService::render() {
  gameEmitter->emit("game/render",
                    {{"log", false}, {"before", true}, {"after", true}});
}

void GameService::deinit() {
  gameEmitter->emit("game/deinit", {{"before", true}, {"after", true}});
}

void GameService::onBeforeInit() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
}

void GameService::onBeforeRender() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}

void GameService::onAfterRender() { EndDrawing(); }

void GameService::onAfterDeinit() { CloseWindow(); }

void GameService::start() {
  gameState.started = true;
  gameEmitter->emit("game/start", {{"before", true}, {"after", true}});
}

bool GameService::isStarted() { return gameState.started; }

void GameService::pause() {
  gameState.paused = true;
  gameEmitter->emit("game/pause", {{"before", true}, {"after", true}});
}
bool GameService::isPaused() { return gameState.paused; }

void GameService::gameOver() {
  gameState.gameOver = true;
  gameEmitter->emit("game/game-over", {{"before", true}, {"after", true}});
}
bool GameService::isGameOver() { return gameState.gameOver; }

void GameService::stop() {
  gameState.close = true;
  gameEmitter->emit("game/stop", {{"before", true}, {"after", true}});
}
bool GameService::shouldClose() {
  return gameState.close || WindowShouldClose();
}

void GameService::resume() {
  gameState.paused = false;
  gameEmitter->emit("game/resume", {{"before", true}, {"after", true}});
}

void GameService::restart() {
  gameState.started = false;
  gameState.paused = false;
  gameState.gameOver = false;
  gameEmitter->emit("game/restart", {{"before", true}, {"after", true}});
}
bool GameService::isRunning() { return gameState.started && !gameState.paused; }

GameState GameService::getGameState() { return gameState; }

std::unique_ptr<GameService> gameService;
} // namespace game
