#include "nebula/nebula.h"

namespace game {
Nebula::Nebula() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
}

void Nebula::onInit() {
  // tile related properties
  nebula.tile.width = NEBULA_TILE_WIDTH;
  nebula.tile.height = NEBULA_TILE_HEIGHT;
  nebula.tile.x = 7;
  nebula.tile.y = 0;
  nebula.position = Vector2{config::WINDOW_WIDTH + nebula.tile.width / 2,
                            config::WINDOW_HEIGHT - nebula.tile.height};

  scheduleService->repeat(
      [this] {
        tileAnimation.sprite++;
        tileAnimation.sprite = std::fmod(
            tileAnimation.sprite,
            tileAnimation
                .spriteTotal); // 8x8 spritesheet, but with only 60 sprites
        nebula.tile.y =
            std::floor(tileAnimation.sprite /
                       tileAnimation.spriteRowSize); // 8x8 spritesheet
        nebula.tile.x =
            std::fmod(tileAnimation.sprite,
                      tileAnimation.spriteRowSize); // 8 sprites per row
      },
      NEBULA_ANIMATION_TIME);
  logService->info("(nebula) Nebula initialized.");
};

void Nebula::onRestart() {
  onInit();
  logService->info("(nebula) Nebula restarted.");
}

void Nebula::onUpdate() {
  if (!gameService->isRunning()) {
    return;
  }

  nebula.position.x += velocity * GetFrameTime();

  // // extremes
  if (nebula.position.x < -nebula.tile.width) {
    nebula.position.x = config::WINDOW_WIDTH + nebula.tile.width;
  }
}

void Nebula::onRender() {
  if (!gameService->isStarted()) {
    return;
  }
  Color color = gameService->isPaused() ? GRAY : WHITE;
  tileService->draw(tileService->textures[TEXTURE_NEBULA], nebula.tile,
                    nebula.position, color);
}
} // namespace game
