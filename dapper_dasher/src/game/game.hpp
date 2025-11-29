#pragma once
#include "player.hpp"

class Game {
  Player player;

public:
  void start();
  void update();
  void render();
  void stop();
};
