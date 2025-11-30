#pragma once
#include "config.hpp"
#include "nebula.hpp"
#include "player.hpp"
#include "tile-service.hpp"
#include "schedule-service.hpp"

class Game {
  Player player;
  Nebula nebula;  
  
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
