#include <cstdio>
#include <iostream>
#include "raylib.h"
#include "./common.hpp"
#include "./game/Game.cpp"
#include "./player/Player.cpp"
#include "./timer/Timer.cpp"

int main() {
  Game game;
  
  game.start();  
  while (!WindowShouldClose()) {
    game.update();
    game.render();    
  }
  game.stop();

  return 0;  
}
