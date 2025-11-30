#include "game.hpp"

void Game::start() {
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");
  SetTargetFPS(60);
  // entities
  player.start();
  nebula.start();
  // static
  TileService::start();
  ScheduleService::start();
}

void Game::update() {
  // entities
  player.update();
  nebula.update();
  // static
  ScheduleService::update();
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
  // entities
  player.stop();
  nebula.stop();
  // static
  TileService::stop();
  ScheduleService::stop();
  CloseWindow();
}
