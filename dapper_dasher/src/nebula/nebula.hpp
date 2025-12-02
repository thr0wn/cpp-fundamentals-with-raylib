#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "raylib.h"
#include "game-service.hpp"
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
#define NEBULA_SPRITE_TOTAL 60
#define NEBULA_SPRITE_ROW_SIZE 8

class Nebula : public GameNode2D {
  const float velocity = INITIAL_VELOCITY;
  TileAnimation tileAnimation = { 0, NEBULA_SPRITE_TOTAL, NEBULA_SPRITE_ROW_SIZE};  

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
