#include "game/game-service.h"

namespace game {
GameService::GameService() : GameNode("game-service") {
  Listener beforeStart("game-service/start:before",
                       [this](Event event) { onBeforeStart(); });
  Listener beforeRender("game-service/render:before",
                        [this](Event event) { onBeforeRender(); });
  Listener afterRender("game-service/render:after",
                       [this](Event event) { onAfterRender(); });
  Listener afterStop("game-service/stop:after",
                     [this](Event event) { onAfterStop(); });

  gameEmitter.on("game/start:before", beforeStart);
  gameEmitter.on("game/render:before", beforeRender);
  gameEmitter.on("game/render:after", afterRender);
  gameEmitter.on("game/stop:after", afterStop);
}

void GameService::start() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.c_str());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
}

void GameService::_update() {
  try {
    if (gameState.started && !gameState.paused) {
      GameNode::_update();
    }
  } catch (...) {
    logService.log("(game-service) Crashed at update");
  }
}

void GameService::_render() {
  try {
    BeginDrawing();
    GameNode::_render();
    ClearBackground(WHITE);
    EndDrawing();
  } catch (...) {
    logService.log("(game-service) Crashed at render");
  }
}

void GameService::_stop() {
  try {
    GameNode::_stop();
    CloseWindow();
  } catch (...) {
    logService.log("(game-service) Crashed at stop");
  }
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
  logService.log("(game-service) Game Started");
}
bool GameService::isStarted() { return gameState.started; }

void GameService::pauseGame() {
  gameState.paused = true;
  logService.log("(game-service) Game Paused");
}
bool GameService::isPaused() { return gameState.paused; }

void GameService::gameOver() {
  gameState.gameOver = true;
  logService.log("(game-service) Game Over");
}
bool GameService::isGameOver() { return gameState.gameOver; }

void GameService::stopGame() {
  gameState.close = true;
  logService.log("(game-service) Game Stopped");
}
bool GameService::shouldClose() {
  return gameState.close || WindowShouldClose();
}

void GameService::resumeGame() {
  gameState.paused = false;
  logService.log("(game-service) Game Resumed");
}

void GameService::restartGame() {
  gameState.started = false;
  gameState.paused = false;
  gameState.gameOver = false;
  _restart();
  logService.log("(game-service) Game Restarted");
}
bool GameService::isRunning() { return gameState.started && !gameState.paused; }

GameState GameService::getGameState() { return gameState; }

Emitter gameEmitter{"game-emitter"};
GameService gameService;
} // namespace game
