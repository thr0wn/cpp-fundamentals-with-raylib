#include "nebula/nebula.h"
#include "tile/tile.h"

namespace game {
Nebula::Nebula() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/init:after", [this](Event event) { onAfterInit(); });
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
}

void Nebula::onInit() {
  // tile related properties
  nebula.tile.width = config::NEBULA_TILE_WIDTH;
  nebula.tile.height = config::NEBULA_TILE_HEIGHT;
  nebula.tile.x = 0;
  nebula.tile.y = 0;
  nebula.position = Vector2{config::WINDOW_WIDTH + nebula.tile.width / 2,
                            config::WINDOW_HEIGHT - nebula.tile.height};

  scheduleService->repeat(
      [this] {
        if (!gameService->isRunning()) {
          return;
        }
        tileAnimation.sprite = std::fmod(
            ++tileAnimation.sprite,
            tileAnimation
                .spriteTotal); // 8x8 spritesheet, but with only 60 sprites
        nebula.tile.y =
            std::floor(tileAnimation.sprite /
                       tileAnimation.spriteRowSize); // 8x8 spritesheet
        nebula.tile.x =
            std::fmod(tileAnimation.sprite,
                      tileAnimation.spriteRowSize); // 8 sprites per row
      },
      config::NEBULA_ANIMATION_TIME);
  gameEmitter->emit({"log/info", std::string("(nebula) Nebula initialized.")});
};

void Nebula::onAfterInit() {
  nebula.tile.loadTexture(TEXTURE_NEBULA);
}

void Nebula::onRestart() {
  onInit();
  gameEmitter->emit({"log/info", std::string("(nebula) Nebula restarted.")});
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
  Tile::draw(nebula.tile, nebula.position, color);
}
} // namespace game
