#pragma once
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"
#include "schedule-service.hpp"
#include "tile-service.hpp"
#include "timer.hpp"
#include <cmath>

#define NEBULA_ANIMATION_TIME .125f
#define INITIAL_VELOCITY -300.0f
#define NEBULA_TILE_WIDTH 100.0f
#define NEBULA_TILE_HEIGHT 100.0f
#define NEBULA_TOTAL_TILES 8

class Nebula : public Entity {
  const float velocity = INITIAL_VELOCITY;

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
