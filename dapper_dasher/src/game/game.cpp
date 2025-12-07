#include "game/game.hpp"

void Game::start() {
  // add game-nodes
  Background *background = new Background();  
  Player *player = new Player();
  Nebula *nebula = new Nebula();
  Start *start = new Start();
  Pause *pause = new Pause();
  Score *score = new Score();
  GameOver *gameOver = new GameOver();
  gameService::addGameNode(background);
  gameService::addGameNode(player);
  gameService::addGameNode(nebula);
  gameService::addGameNode(start);
  gameService::addGameNode(pause);
  gameService::addGameNode(score);  
  gameService::addGameNode(gameOver);

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
