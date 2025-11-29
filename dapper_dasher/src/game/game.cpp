#include "config.hpp"
#include "game.hpp"
#include "player.hpp"
#include "tile-controller.hpp"

void Game::start() {
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");
  SetTargetFPS(60);
  player.start();
  TileController::start();
}

void Game::update() { player.update(); }

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);
  player.render();
  EndDrawing();
}

void Game::stop() {
  player.stop();
  CloseWindow();
}
