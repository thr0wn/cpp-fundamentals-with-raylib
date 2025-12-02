#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "nebula.hpp"
#include "player.hpp"
#include "background.hpp"
#include "game-service.hpp"
#include "tile-service.hpp"
#include "schedule-service.hpp"
#include "start.hpp"
#include "pause.hpp"

class Game {
public:
  // start the game and run game entities
  void start();
  // update game logic
  void update();
  // render game entities
  void render();
// render outside draw  
  void renderOut();
  // stop updating and rendering
  void stop();
  // should close the game
  bool shouldClose();  
};
