#pragma once
#include "../common.hpp"

void Player::start() {
}

void Player::update() {
  if (IsKeyDown(KEY_SPACE) && position.y == (Game::windowHeight - height)) {
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
  if (position.y > (Game::windowHeight - height)) {
    position.y = Game::windowHeight - height;
  }
}

void Player::render() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}


void Player::stop() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}
