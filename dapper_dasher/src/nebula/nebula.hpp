#pragma once
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"
#include "timer.hpp"

#define NEBULA_ANIMATION_TIME .125f
#define INITIAL_VELOCITY -300.0f
#define NEBULA_TILE_WIDTH 100.0f
#define NEBULA_TILE_HEIGHT 100.0f
#define NEBULA_TOTAL_TILES 8

class Nebula : public Entity {
  const float velocity = INITIAL_VELOCITY;
  Timer animationTimer{NEBULA_ANIMATION_TIME};
  
public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
