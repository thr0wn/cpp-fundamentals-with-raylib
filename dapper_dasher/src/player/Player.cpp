#pragma once
#include "../common.hpp"
#include "../timer/Timer.cpp"

class Player : public Entity {
  float width = 50;
  float height = 80;

  Vector2 position = Vector2{windowWidth/2 - width/2, windowHeight - height/2};
  const float initialVelocity = 10.0f;
  float velocity = initialVelocity;
  float jumpVelocity = -10.0f;
  Timer jumpTimer{.25f};

public:
  void start() override{};

  void update() override {
    if (IsKeyDown(KEY_SPACE) && position.y == (windowHeight - height)) {
      jumpTimer.start();
    }

    if (jumpTimer.isActive()) {
      velocity = jumpVelocity;
    } else {
      velocity = initialVelocity;
    }

    position.y += velocity;

    // extremes
    if (position.y < 0) {
      position.y = 0;
    }
    if (position.y > (windowHeight - height)) {
      position.y = windowHeight - height;
    }
  }

  void render() override {
    DrawRectangle(position.x, position.y, width, height, BLUE);
  }

  void stop() override{};
};
