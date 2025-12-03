#include "game/game.hpp"

void Game::start() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, "Dapper Dasher");
  SetTargetFPS(60);
  
  // add game-nodes
  Background *background = new Background();  
  Player *player = new Player();
  Nebula *nebula = new Nebula();
  Start *start = new Start();
  gameService::addGameNode(background);
  gameService::addGameNode(player);
  gameService::addGameNode(nebula);
  gameService::addGameNode(start);

  gameService::start();  
}

void Game::update() { gameService::update(); }

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);
  gameService::render();
  gameService::renderOut();
  EndDrawing();
}

void Game::stop() {
  gameService::stop();
}

bool Game::shouldClose () {
  return gameService::shouldClose();
}  
