#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raylib.h"
#include "tile/texture-loader.h"
#include "tile/tile.h"
#include "timer/timer.h"
#include <cmath>
#include <map>

namespace game {
class Nebula {
  GameNode2D nebula{"nebula-node"};
  const float velocity = config::INITIAL_VELOCITY;
  TileAnimation tileAnimation = {0, config::NEBULA_SPRITE_TOTAL,
                                 config::NEBULA_SPRITE_ROW_SIZE};
  Timer animationTimer{config::NEBULA_ANIMATION_TIME};

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  TextureLoader *textureLoader = AsyncPointer::get<TextureLoader>();
  Log *log = AsyncPointer::get<Log>();

public:
  Nebula() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/restart", [this](Event event) { onRestart(); });
    emitter->on("game/update", [this](Event event) { onUpdate(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  }

  void onInit() {
    Rectangle collisionRectangle = {0, 0, config::NEBULA_TILE_WIDTH, config::NEBULA_TILE_HEIGHT};
    nebula.getCollisionGeometry().setRaw(collisionRectangle);

    Tile &tile = nebula.getTile();
    tile.width = config::NEBULA_TILE_WIDTH;
    tile.height = config::NEBULA_TILE_HEIGHT;
    tile.x = 0;
    tile.y = 0;
    tile.setTexture(textureLoader->textures[TEXTURE_NEBULA]);
    nebula.setPosition(Vector2{config::WINDOW_WIDTH + tile.width / 2,
                               config::WINDOW_HEIGHT - tile.height});
    log->info("(nebula) Nebula initialized.");
  };

  void onRestart() {
    onInit();
    log->info("(nebula) Nebula restarted.");
  }

  void onUpdate() {
    if (!gameState->isRunning()) {
      return;
    }

    Tile &tile = nebula.getTile();
    Vector2 &position = nebula.getPosition();

    position.x += velocity * GetFrameTime();

    // // extremes
    if (position.x < -tile.width) {
      position.x = config::WINDOW_WIDTH + tile.width;
    }

    if (!animationTimer.isActive()) {
      tileAnimation.sprite = std::fmod(
          ++tileAnimation.sprite,
          tileAnimation
              .spriteTotal); // 8x8 spritesheet, but with only 60 sprites
      tile.y = std::floor(tileAnimation.sprite /
                          tileAnimation.spriteRowSize); // 8x8 spritesheet
      tile.x = std::fmod(tileAnimation.sprite,
                         tileAnimation.spriteRowSize); // 8 sprites per row
      animationTimer.start();
    }

    nebula.update();    
  }

  void onRender() {
    if (!gameState->isStarted()) {
      return;
    }
    nebula.setColor(gameState->isRunning() ? WHITE : GRAY);
    nebula.render();
    nebula.getUpdatedCollisionGeometry().render();    
  }

  GameNode2D &getNebula() { return nebula; }
};
} // namespace game
