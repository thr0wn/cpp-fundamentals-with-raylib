#pragma once
#include "config.hpp"
#include "entity.hpp"
#include "raylib.h"

#define JUMP_TIME 0.25f
#define INITIAL_GRAVITY 1000.0f
#define JUMP_VELOCITY -500.0f

class Player : public Entity {
  Vector2 position;
  const float gravity = INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = JUMP_VELOCITY;

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
