#pragma once
#include "player.hpp"
#include "tile-controller.hpp"

class Game {
  Player player;
  
public:
  // start the game and run game entities
  void start();
  // update game logic
  void update();
  // render game entities
  void render();
  // stop updating and rendering  
  void stop();
};
