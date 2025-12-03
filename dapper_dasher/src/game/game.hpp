#pragma once
#include "background/background.hpp"
#include "config/config.hpp"
#include "nebula/nebula.hpp"
#include "player/player.hpp"
#include "raylib.h"
#include "ui/start.hpp"
#include "ui/pause.hpp"


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
