#include "game/game-service.h"

namespace game {
GameService::GameService() {
  gameEmitter->on("game/start:before", [this](Event event) { onBeforeStart(); });
  gameEmitter->on("game/render:before",
                 [this](Event event) { onBeforeRender(); });
  gameEmitter->on("game/render:after", [this](Event event) { onAfterRender(); });
  gameEmitter->on("game/stop:after", [this](Event event) { onAfterStop(); });
}

void GameService::start() {
  Event beforeStartEvent{"game/start:before", {}};
  Event startEvent{"game/start", {}};
  Event afterStartEvent{"game/start:after", {}};

  gameEmitter->emit(beforeStartEvent);
  gameEmitter->emit(startEvent);
  gameEmitter->emit(afterStartEvent);
}

void GameService::update() {
  Event beforeUpdateEvent{"game/update:before", {}};
  Event updateEvent{"game/update", {}};
  Event afterUpdateEvent{"game/update:after", {}};

  gameEmitter->emit(beforeUpdateEvent, {{"log", false}});
  gameEmitter->emit(updateEvent, {{"log", false}});
  gameEmitter->emit(afterUpdateEvent, {{"log", false}});
}

void GameService::render() {
  Event beforeRenderEvent{"game/render:before", {}};
  Event renderEvent{"game/render", {}};
  Event afterRenderEvent{"game/render:after", {}};

  gameEmitter->emit(beforeRenderEvent, {{"log", false}});
  gameEmitter->emit(renderEvent, {{"log", false}});
  gameEmitter->emit(afterRenderEvent, {{"log", false}});
}

void GameService::stop() {
  Event beforeStopEvent{"game/stop:before", {}};
  Event stopEvent{"game/stop", {}};
  Event afterStopEvent{"game/stop:after", {}};

  gameEmitter->emit(beforeStopEvent);
  gameEmitter->emit(stopEvent);
  gameEmitter->emit(afterStopEvent);
}

void GameService::onBeforeStart() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
}

void GameService::onBeforeRender() {
  BeginDrawing();
  ClearBackground(WHITE);
}

void GameService::onAfterRender() { EndDrawing(); }

void GameService::onAfterStop() { CloseWindow(); }

void GameService::startGame() {
  gameState.started = true;
  logService->log("(game-service) Game Started");
}
bool GameService::isStarted() { return gameState.started; }

void GameService::pauseGame() {
  gameState.paused = true;
  logService->log("(game-service) Game Paused");
}
bool GameService::isPaused() { return gameState.paused; }

void GameService::gameOver() {
  gameState.gameOver = true;
  logService->log("(game-service) Game Over");
}
bool GameService::isGameOver() { return gameState.gameOver; }

void GameService::stopGame() {
  gameState.close = true;
  logService->log("(game-service) Game Stopped");
}
bool GameService::shouldClose() {
  return gameState.close || WindowShouldClose();
}

void GameService::resumeGame() {
  gameState.paused = false;
  logService->log("(game-service) Game Resumed");
}

void GameService::restartGame() {
  gameState.started = false;
  gameState.paused = false;
  gameState.gameOver = false;
  logService->log("(game-service) Game Restarted");
}
bool GameService::isRunning() { return gameState.started && !gameState.paused; }

GameState GameService::getGameState() { return gameState; }

std::unique_ptr<GameService> gameService;
} // namespace game
