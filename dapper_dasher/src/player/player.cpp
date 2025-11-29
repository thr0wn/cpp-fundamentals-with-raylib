#include "common.hpp"
#include "player.hpp"
#include "config.hpp"
#include "timer.cpp"

void Player::start() {};

void Player::update() {
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

void Player::render() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}

void Player::stop() {};
