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
}

void restart() {
  // static
  scheduleService::stop(); 
  // game-nodes: start
  for (GameNode *gameNode : gameNodes) {
    gameNode->stop();
    gameNode->start();
  }
}

void update() {
  // game-nodes: update
  if (gameState.started && !gameState.paused) {
    for (GameNode *gameNode : gameNodes) {
      gameNode->update();
    }
    // services
    scheduleService::update();
  }
}

void render() {
  BeginDrawing();
  // game-nodes: render
  for (GameNode *gameNode : gameNodes) {
    gameNode->render();
  }
  ClearBackground(WHITE);
  EndDrawing();
  gameService::renderOut();  
}

void renderOut() {
  // game-nodes: render outside draw
  for (GameNode *gameNode : gameNodes) {
    gameNode->renderOut();
  }
}

void stop() {
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
}

void startGame() { gameState.started = true; }
bool isStarted() { return gameState.started; }
void pauseGame() { gameState.paused = true; }
bool isPaused() { return gameState.paused; }
void stopGame() { gameState.close = true; }
bool shouldClose() { return gameState.close || WindowShouldClose(); }
void resumeGame() { gameState.paused = false; }
void restartGame() {
  gameState.paused = false;
  gameState.started = false;
  restart();
}
bool isRunning() { return gameState.started && !gameState.paused; }

GameState getGameState() { return gameState; }
} // namespace gameService
