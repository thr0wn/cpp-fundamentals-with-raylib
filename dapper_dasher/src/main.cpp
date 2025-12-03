#include <cstdio>
#include <iostream>
#include "game.hpp"

int main() {
  Game game;
  
  game.start();  
  while (!game.shouldClose()) {
    game.update();
    game.render();    
  }
  game.stop();

  return 0;
}
