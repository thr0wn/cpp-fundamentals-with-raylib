#include <cstdio>
#include <iostream>
#include "raylib.h"
#include "./game/Game.cpp"
#include "./player/Player.cpp"
#include "./timer/Timer.cpp"

int main() {
  Game game;
  
  game.start();  
  while (WindowShouldClose() == false) {
    game.update();
    game.render();    
  }

  game.stop();
}
