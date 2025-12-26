#include "game/game-service.h"
#include "tile/tile.h"

namespace game {
GameService::GameService() {
  gameEmitter->on("game/init:before", [this](Event event) { onBeforeInit(); });
  gameEmitter->on("game/render:before",
                 [this](Event event) { onBeforeRender(); });
  gameEmitter->on("game/render:after", [this](Event event) { onAfterRender(); });
  gameEmitter->on("game/deinit:after", [this](Event event) { onAfterDeinit(); });
}

void GameService::init() {
  gameEmitter->emit("game/init");
}

void GameService::update() {
  Event updateEvent{"game/update", {}};
  gameEmitter->emit(updateEvent, {{"log", false}});
}

void GameService::render() {
  Event renderEvent{"game/render", {}};
  gameEmitter->emit(renderEvent, {{"log", false}});
}

void GameService::deinit() {
  gameEmitter->emit("game/deinit");
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
  gameEmitter->emit("game/start");
}
bool GameService::isStarted() { return gameState.started; }

void GameService::pause() {
  gameState.paused = true;
  gameEmitter->emit("game/pause");
}
bool GameService::isPaused() { return gameState.paused; }

void GameService::gameOver() {
  gameState.gameOver = true;
  gameEmitter->emit("game/game-over");
}
bool GameService::isGameOver() { return gameState.gameOver; }

void GameService::stop() {
  gameState.close = true;
  gameEmitter->emit("game/stop");  
}
bool GameService::shouldClose() {
  return gameState.close || WindowShouldClose();
}

void GameService::resume() {
  gameState.paused = false;
  gameEmitter->emit("game/resume");  
}

void GameService::restart() {
  gameState.started = false;
  gameState.paused = false;
  gameState.gameOver = false;
  gameEmitter->emit("game/restart");
}
bool GameService::isRunning() { return gameState.started && !gameState.paused; }

GameState GameService::getGameState() { return gameState; }

std::unique_ptr<GameService> gameService;
} // namespace game
