#include "game.hpp"

void Game::start() {
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");
  SetTargetFPS(60);
  TileController::start();

  // entities
  player.start();
  nebula.start();
}

void Game::update() {
  // entities
  player.update();
  nebula.update();
}

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);
  // entities
  player.render();
  nebula.render();  
  EndDrawing();
}

void Game::stop() {
  TileController::stop();
  // entities
  player.stop();
  nebula.stop();  
  CloseWindow();
}
