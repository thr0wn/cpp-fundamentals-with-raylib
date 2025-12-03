#include "game.hpp"
#include "raylib.h"

void Game::start() {
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");
  SetTargetFPS(60);
  
  // add game-nodes
  Background *background = new Background();  
  Player *player = new Player();
  Nebula *nebula = new Nebula();
  Start *start = new Start();
  GameService::addGameNode(background);
  GameService::addGameNode(player);
  GameService::addGameNode(nebula);
  GameService::addGameNode(start);

  GameService::start();  
}

void Game::update() { GameService::update(); }

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);
  GameService::render();
  GameService::renderOut();
  EndDrawing();
}

void Game::stop() {
  GameService::stop();
}

bool Game::shouldClose () {
  return GameService::shouldClose();
}  
