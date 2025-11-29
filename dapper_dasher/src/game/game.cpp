#pragma once
#include "raylib.h"
#include "player.cpp"

class Game {
  Player player;

public:
  void start() {
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");
    SetTargetFPS(60);
    player.start();
  }

  void update() { player.update(); }

  void render() {
    BeginDrawing();
    ClearBackground(WHITE);
    player.render();
    EndDrawing();
  }

  void stop() {
    player.stop();
    CloseWindow();
  }
};
