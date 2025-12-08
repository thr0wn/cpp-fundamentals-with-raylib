#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-service.h"
#include "raylib.h"
#include "tile/tile-service.h"
#include "tile/tile.h"
#include "timer/schedule-service.h"
#include "timer/timer.h"
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

namespace game {
class Nebula : public GameNode2D {
  const float velocity = INITIAL_VELOCITY;
  TileAnimation tileAnimation = {0, NEBULA_SPRITE_TOTAL,
                                 NEBULA_SPRITE_ROW_SIZE};

public:
  Nebula();
  
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
} // namespace game
