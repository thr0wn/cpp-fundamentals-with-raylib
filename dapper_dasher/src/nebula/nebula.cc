#include "nebula/nebula.h"

namespace game {
Nebula::Nebula() : GameNode2D("nebula") {}

void Nebula::start() {
  // tile related properties
  tile.width = NEBULA_TILE_WIDTH;
  tile.height = NEBULA_TILE_HEIGHT;
  tile.x = 7;
  tile.y = 0;
  position = Vector2{config::WINDOW_WIDTH + tile.width / 2,
                     config::WINDOW_HEIGHT - tile.height};

  scheduleService.repeat(
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

void Nebula::restart() {
  start();  
}


void Nebula::update() {
  position.x += velocity * GetFrameTime();

  // // extremes
  if (position.x < -tile.width) {
    position.x = config::WINDOW_WIDTH + tile.width;
  }
}

void Nebula::render() {
  if (!gameService.isStarted()) {
    return;
  }
  Color color = gameService.isPaused() ? GRAY : WHITE;
  tileService.draw(tileService.textures[TEXTURE_NEBULA], tile, position,
                    color);
}

void Nebula::stop(){};
} // namespace game
