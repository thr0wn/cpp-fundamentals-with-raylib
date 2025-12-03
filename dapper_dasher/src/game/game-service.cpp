#include "game/game-service.hpp"

GameState GameService::gameState;
std::list<GameNode *> GameService::gameNodes;

void GameService::addGameNode(GameNode *gameNode) {
  gameNodes.push_back(gameNode);
}

void GameService::removeGameNode(GameNode *gameNode) {
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

void GameService::start() {
  // static
  TileService::start();
  ScheduleService::start();
  // game-nodes: start
  for (GameNode *gameNode : gameNodes) {
    gameNode->start();
  }
}

void GameService::update() {
  // game-nodes: update
  if (gameState.started && !gameState.paused) {
    for (GameNode *gameNode : gameNodes) {
      gameNode->update();
    }
    // static
    ScheduleService::update();
  }
}

void GameService::render() {
  // game-nodes: render
  for (GameNode *gameNode : gameNodes) {
    gameNode->render();
  }
}

void GameService::renderOut() {
  // game-nodes: render outside draw
  for (GameNode *gameNode : gameNodes) {
    gameNode->renderOut();
  }
}

void GameService::stop() {
  // static calls
  TileService::stop();
  ScheduleService::stop();
  // game-nodes: stop
  for (GameNode *gameNode : gameNodes) {
    gameNode->stop();
    delete gameNode;
  }
  gameNodes.clear();
  CloseWindow();
}

void GameService::startGame() { gameState.started = true; }
void GameService::pauseGame() { gameState.paused = true; }
void GameService::closeGame() { gameState.close = true; }

bool GameService::isStartUI() { return !gameState.started; }
bool GameService::isPauseUI() { return gameState.started && !gameState.paused; }

bool GameService::shouldClose() {
  return gameState.close || WindowShouldClose();
}

GameState GameService::getGameState() { return gameState; }
