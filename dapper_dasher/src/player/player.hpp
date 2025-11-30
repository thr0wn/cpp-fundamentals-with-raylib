#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "raylib.h"
#include "schedule-service.hpp"
#include "tile-service.hpp"
#include "tile.hpp"
#include "timer.hpp"
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
