#pragma once
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"
#include "schedule-service.hpp"
#include "tile-service.hpp"
#include "tile.hpp"
#include "timer.hpp"
#include <cmath>

// movement
#define NEBULA_ANIMATION_TIME .125f
#define INITIAL_VELOCITY -300.0f

// tile
#define NEBULA_TILE_WIDTH 100.0f
#define NEBULA_TILE_HEIGHT 100.0f

// tile animation
#define NEBULA_TILE_TOTAL 60
#define NEBULA_TILE_ROW_SIZE 8

class Nebula : public Entity {
  const float velocity = INITIAL_VELOCITY;
  TileAnimation tileAnimation = { 0, NEBULA_TILE_TOTAL, NEBULA_TILE_ROW_SIZE };  

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
