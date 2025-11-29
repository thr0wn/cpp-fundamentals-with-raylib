#pragma once
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"
#include "timer.hpp"

#define ANIMATION_TIME .125f
#define INITIAL_GRAVITY 1000.0f
#define JUMP_VELOCITY -500.0f
#define PLAYER_TILE_WIDTH 128
#define PLAYER_TILE_HEIGHT 128

class Player : public Entity {
  Vector2 position;
  const float gravity = INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = JUMP_VELOCITY;
  Timer animationTimer{ANIMATION_TIME};
  
public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
