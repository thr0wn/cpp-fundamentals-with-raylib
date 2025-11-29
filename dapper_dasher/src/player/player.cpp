#include "config.hpp"
#include "player.hpp"
#include "config.hpp"
#include "raylib.h"
#include "tile.hpp"
#include "timer.hpp"
#include "tile-controller.hpp"
#include <cstdio>
#include <cmath>

void Player::start() {
  // tile related properties  
  tile.width = PLAYER_TILE_WIDTH;
  tile.height = PLAYER_TILE_HEIGHT;
  tile.x = 0;
  tile.y = 0;
  position =
      Vector2{windowWidth / 2 - tile.width / 2, windowHeight - tile.height};

  // animation
  animationTimer.start();  
};

void Player::update() {
  if (IsKeyDown(KEY_SPACE) && position.y == (windowHeight - tile.height)) {
    velocity = jumpVelocity;
  } else {
    velocity += gravity * GetFrameTime();
  } 

  position.y += velocity * GetFrameTime();
  
  // extremes
  if (position.y < 0) {
    position.y = 0;
  }
  if (position.y > (windowHeight - tile.height)) {
    position.y = windowHeight - tile.height;
  }

  // animation
  if (!animationTimer.isActive()) {
    tile.x++;
    tile.x = std::fmod(tile.x, 6.0f * PLAYER_TILE_WIDTH);
    animationTimer.start();
  }
}

void Player::render() {
  TileController::draw(tile, position, TileController::textures[TEXTURE_SCARFY]);
}

void Player::stop() {};
