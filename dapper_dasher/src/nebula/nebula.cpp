#include "nebula.hpp"
#include "config.hpp"
#include <cstdio>

void Nebula::start() {
  // tile related properties  
  tile.width = NEBULA_TILE_WIDTH;
  tile.height = NEBULA_TILE_HEIGHT;
  tile.x = 7;
  tile.y = 0;
  position =
      Vector2{windowWidth + tile.width / 2, windowHeight - tile.height};

  ScheduleService::repeat(
      [this] {
        tileAnimation.sprite++;
        tileAnimation.sprite = std::fmod(tileAnimation.sprite, NEBULA_TILE_TOTAL); // 8x8 spritesheet, but with only 60 sprites
        tile.y = std::floor(tileAnimation.sprite/NEBULA_TILE_ROW_SIZE); // 8x8 spritesheet
        tile.x = std::fmod(tileAnimation.sprite, NEBULA_TILE_ROW_SIZE); // 8 sprites per row
      },
      NEBULA_ANIMATION_TIME);
};

void Nebula::update() {
  position.x += velocity * GetFrameTime();

  // // extremes
  if (position.x < -tile.width) {
    position.x = windowWidth + tile.width;
  }
}

void Nebula::render() {
  TileService::draw(TileService::textures[TEXTURE_NEBULA], tile, position);
}

void Nebula::stop() {};
