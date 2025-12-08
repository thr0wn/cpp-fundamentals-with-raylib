#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "raylib.h"
#include "tile/tile-service.hpp"
#include "tile/tile.hpp"
#include "timer/schedule-service.hpp"
#include "timer/timer.hpp"
#include <cmath>
#include <cstdio>

// movement
#define PLAYER_ANIMATION_TIME .125f
#define PLAYER_INITIAL_GRAVITY 1000.0f
#define PLAYER_JUMP_VELOCITY -500.0f

// tile
#define PLAYER_TILE_WIDTH 128
#define PLAYER_TILE_HEIGHT 128

// tile animation
#define PLAYER_SPRITE_TOTAL 6

namespace game {
class Player : public GameNode2D {
  const float gravity = PLAYER_INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = PLAYER_JUMP_VELOCITY;
  TileAnimation tileAnimation = {0, PLAYER_SPRITE_TOTAL};

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;

  bool isJumping();
};
} // namespace game
