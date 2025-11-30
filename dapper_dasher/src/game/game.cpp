#include "game.hpp"

void Game::start() {
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");
  SetTargetFPS(60);
  // static
  TileService::start();
  ScheduleService::start();
  // game-nodes
  Player *player = new Player();
  Nebula *nebula = new Nebula();
  Background *background = new Background();
  gameNodes = {background, player, nebula};
  // game-nodes: start
  for (GameNode *gameNode : gameNodes) {
    gameNode->start();
  }
}

void Game::update() {
  // static
  ScheduleService::update();
  // game-nodes: update
  for (GameNode *gameNode : gameNodes) {
    gameNode->update();
  }
}

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);
  // game-nodes: render
  for (GameNode *gameNode : gameNodes) {
    gameNode->render();
  }
  EndDrawing();
}

void Game::stop() {
  // static
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
