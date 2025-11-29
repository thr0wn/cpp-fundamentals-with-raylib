#pragma once
#include "common.hpp"
#include "timer.hpp"
#include "raylib.h"

class Player : public Entity {
  float width = 50;
  float height = 80;

  Vector2 position = Vector2{windowWidth/2 - width/2, windowHeight - height/2};
  const float initialVelocity = 10.0f;
  float velocity = initialVelocity;
  float jumpVelocity = -10.0f;
  Timer jumpTimer{.25f};

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
