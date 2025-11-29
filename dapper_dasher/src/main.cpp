#include <cstdio>
#include <iostream>
#include "raylib.h"
#include "game.hpp"

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
