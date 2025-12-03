#include "game/game.hpp"

void Game::start() {
  // add game-nodes
  Background *background = new Background();  
  Player *player = new Player();
  Nebula *nebula = new Nebula();
  Start *start = new Start();
  Pause *pause = new Pause();
  gameService::addGameNode(background);
  gameService::addGameNode(player);
  gameService::addGameNode(nebula);
  gameService::addGameNode(pause);
  gameService::addGameNode(start);

  gameService::start();  
}

void Game::update() { gameService::update(); }

void Game::render() {
  gameService::render();
}

void Game::stop() {
  gameService::stop();
}

bool Game::shouldClose () {
  return gameService::shouldClose();
}  
