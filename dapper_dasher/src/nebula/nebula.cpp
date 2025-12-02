#include "nebula.hpp"

void Nebula::start() {
  // tile related properties
  tile.width = NEBULA_TILE_WIDTH;
  tile.height = NEBULA_TILE_HEIGHT;
  tile.x = 7;
  tile.y = 0;
  position = Vector2{windowWidth + tile.width / 2, windowHeight - tile.height};

  ScheduleService::repeat(
      [this] {
        tileAnimation.sprite++;
        tileAnimation.sprite = std::fmod(
            tileAnimation.sprite,
            tileAnimation
                .spriteTotal); // 8x8 spritesheet, but with only 60 sprites
        tile.y = std::floor(tileAnimation.sprite /
                            tileAnimation.spriteRowSize); // 8x8 spritesheet
        tile.x = std::fmod(tileAnimation.sprite,
                           tileAnimation.spriteRowSize); // 8 sprites per row
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
  GameState gameState = GameService::getGameState();
  if (!gameState.started) {
    return;
  }
  TileService::draw(TileService::textures[TEXTURE_NEBULA], tile, position);
}

void Nebula::stop(){};
