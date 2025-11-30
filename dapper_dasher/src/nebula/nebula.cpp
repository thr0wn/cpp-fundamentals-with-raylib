#include "config.hpp"
#include "nebula.hpp"
#include "config.hpp"
#include "raylib.h"
#include "tile.hpp"
#include "timer.hpp"
#include "tile-controller.hpp"
#include <cstdio>
#include <cmath>

void Nebula::start() {
  // tile related properties  
  tile.width = NEBULA_TILE_WIDTH;
  tile.height = NEBULA_TILE_HEIGHT;
  tile.x = 7;
  tile.y = 0;
  position =
      Vector2{windowWidth + tile.width / 2, windowHeight - tile.height};

  // animation
  animationTimer.start();  
};

void Nebula::update() {
  position.x += velocity * GetFrameTime();
  
  // extremes
  if (position.x < 0) {
    position.x = windowWidth + tile.width/2;
  }

  // animation
  if (!animationTimer.isActive()) {
    tile.x++;
    tile.x = std::fmod(tile.x, NEBULA_TOTAL_TILES);
    animationTimer.start();
  }
}

void Nebula::render() {
  TileController::draw(tile, position, TileController::textures[TEXTURE_NEBULA]);
}

void Nebula::stop() {};
