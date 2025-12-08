#include "game/game-service.hpp"

namespace game {
  GameService::GameService(): GameNode("game-service") {}
  
  void GameService::start() {
    InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
               config::GAME_NAME.data());
    SetTargetFPS(60);

    // Disable default close with
    SetExitKey(KEY_NULL);
  }

  void GameService::_update() {
    if (gameState.started && !gameState.paused) {
      GameNode::_update();
    }
  }

  void GameService::_render() {
    try {
      BeginDrawing();
      GameNode::_render();
      ClearBackground(WHITE);
      EndDrawing();
    } catch (...) {
      logService->log("(game-service) Crashed at render");
    }
  }

  void GameService::stop() { CloseWindow(); }

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
    restart();
    logService->log("(game-service) Game Restarted");
  }
  bool GameService::isRunning() { return gameState.started && !gameState.paused; }

  GameState GameService::getGameState() { return gameState; }

  GameService *gameService;
} // namespace game
