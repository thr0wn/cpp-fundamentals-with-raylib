#include "game/game-service.hpp"

namespace gameService {
namespace {
static GameState gameState;
static std::list<GameNode *> gameNodes;
} // namespace

void addGameNode(GameNode *gameNode) { gameNodes.push_back(gameNode); }

void removeGameNode(GameNode *gameNode) {
  std::list<GameNode *>::iterator iterator;
  bool found = false;
  for (GameNode *gNode : gameNodes) {
    if (gNode == gameNode) {
      gameNode->stop();
      delete gameNode;
      found = true;
      break;
    }
    iterator++;
  }
  if (found) {
    gameNodes.erase(iterator);
  }
}

void start() {
  try {
    InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, "Dapper Dasher");
    SetTargetFPS(60);

    // services
    tileService::start();
    scheduleService::start();
    databaseService::start();
    // game-nodes: start
    for (GameNode *gameNode : gameNodes) {
      gameNode->start();
    }

    // Disable default close with
    SetExitKey(KEY_NULL);

    logService::log("(game-service) Started");
  } catch (...) {
    logService::log("(game-service) Crashed at start");
  }
}

void restart() {
  try {
    // static
    scheduleService::stop();
    // game-nodes: start
    for (GameNode *gameNode : gameNodes) {
      gameNode->stop();
      gameNode->start();
    }
    logService::log("(game-service) Restarted");
  } catch (...) {
    logService::log("(game-service) Crashed at restart");
  }
}

void update() {
  try {
    // game-nodes: update
    if (gameState.started && !gameState.paused) {
      for (GameNode *gameNode : gameNodes) {
        gameNode->update();
      }
      // services
      scheduleService::update();
    }
  } catch (...) {
    logService::log("(game-service) Crashed at update");
  }
}

void render() {
  try {
    BeginDrawing();
    // game-nodes: render
    for (GameNode *gameNode : gameNodes) {
      gameNode->render();
    }
    ClearBackground(WHITE);
    EndDrawing();
    gameService::renderOut();
  } catch (...) {
    logService::log("(game-service) Crashed at render");
  }
}

void renderOut() {
  try {
    // game-nodes: render outside draw
    for (GameNode *gameNode : gameNodes) {
      gameNode->renderOut();
    }
  } catch (...) {
    logService::log("(game-service) Crashed at renderOut");
  }
}

void stop() {
  try {
    // game-nodes: stop
    for (GameNode *gameNode : gameNodes) {
      gameNode->stop();
      delete gameNode;
    }
    gameNodes.clear();
    // services
    tileService::stop();
    scheduleService::stop();
    databaseService::stop();
    CloseWindow();
    logService::log("(game-service) Stopped");
  } catch (...) {
    logService::log("(game-service) Crashed at stop");
  }
}

void startGame() {
  gameState.started = true;
  logService::log("(game-service) Game Started");
}
bool isStarted() { return gameState.started; }
void pauseGame() {
  gameState.paused = true;
  logService::log("(game-service) Game Paused");
}
bool isPaused() { return gameState.paused; }
void stopGame() {
  gameState.close = true;
  logService::log("(game-service) Game Stopped");
}
bool shouldClose() { return gameState.close || WindowShouldClose(); }
void resumeGame() {
  gameState.paused = false;
  logService::log("(game-service) Game Resumed");
}
void restartGame() {
  gameState.paused = false;
  gameState.started = false;
  restart();
  logService::log("(game-service) Game Restarted");
}
bool isRunning() { return gameState.started && !gameState.paused; }

GameState getGameState() { return gameState; }
} // namespace gameService
