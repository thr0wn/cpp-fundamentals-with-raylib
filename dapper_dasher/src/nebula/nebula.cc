#include "nebula/nebula.h"

namespace game {
Nebula::Nebula() {
  emitter->on("game/init", [this](Event event) { onInit(); });
  emitter->on("game/restart", [this](Event event) { onRestart(); });
  emitter->on("game/update", [this](Event event) { onUpdate(); });
  emitter->on("game/render", [this](Event event) { onRender(); });
}

void Nebula::onInit() {
  // tile related properties
  nebula.tile.width = config::NEBULA_TILE_WIDTH;
  nebula.tile.height = config::NEBULA_TILE_HEIGHT;
  nebula.tile.x = 0;
  nebula.tile.y = 0;
  nebula.tile.setTexture(textureLoader->textures[TEXTURE_NEBULA]);
  nebula.position = Vector2{config::WINDOW_WIDTH + nebula.tile.width / 2,
                            config::WINDOW_HEIGHT - nebula.tile.height};
  log->info("(nebula) Nebula initialized.");
};

void Nebula::onRestart() {
  onInit();
  log->info("(nebula) Nebula restarted.");
}

void Nebula::onUpdate() {
  if (!gameState->isRunning()) {
    return;
  }

  nebula.position.x += velocity * GetFrameTime();

  // // extremes
  if (nebula.position.x < -nebula.tile.width) {
    nebula.position.x = config::WINDOW_WIDTH + nebula.tile.width;
  }

  if (!animationTimer.isActive()) {
    tileAnimation.sprite = std::fmod(
        ++tileAnimation.sprite,
        tileAnimation.spriteTotal); // 8x8 spritesheet, but with only 60 sprites
    nebula.tile.y = std::floor(tileAnimation.sprite /
                               tileAnimation.spriteRowSize); // 8x8 spritesheet
    nebula.tile.x = std::fmod(tileAnimation.sprite,
                              tileAnimation.spriteRowSize); // 8 sprites per row
    animationTimer.start();
  }
}

void Nebula::onRender() {
  if (!gameState->isStarted()) {
    return;
  }
  Color color = gameState->isPaused() ? GRAY : WHITE;
  Tile::draw(nebula.tile, nebula.position, color);
}
} // namespace game
