#pragma once
#include <cmath>
#include <cstdio>
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"
#include "tile-service.hpp"
#include "tile.hpp"
#include "timer.hpp"

// movement
#define PLAYER_ANIMATION_TIME .125f
#define INITIAL_GRAVITY 1000.0f
#define JUMP_VELOCITY -500.0f

// tile
#define PLAYER_TILE_WIDTH 128
#define PLAYER_TILE_HEIGHT 128

// tile animation
#define PLAYER_TILE_TOTAL 6

class Player : public Entity {
  const float gravity = INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = JUMP_VELOCITY;
  TileAnimation tileAnimation;
  
public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
  
  bool isJumping();
};
