#include "nebula.hpp"

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
        tile.x++;
        tile.x = std::fmod(tile.x, NEBULA_TOTAL_TILES);        
      },
      NEBULA_ANIMATION_TIME);
};

void Nebula::update() {
  position.x += velocity * GetFrameTime();
  
  // extremes
  if (position.x < 0) {
    position.x = windowWidth + tile.width/2;
  }
}

void Nebula::render() {
  TileService::draw(TileService::textures[TEXTURE_NEBULA], tile, position);
}

void Nebula::stop() {};
