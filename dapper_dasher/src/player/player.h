#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "game/game-state.h"
#include "log/log.h"
#include "nebula/nebula.h"
#include "raylib.h"
#include "tile/texture-loader.h"
#include "tile/tile.h"
#include "timer/timer.h"
#include <cmath>
#include <cstdio>
#include <map>

namespace game {
class Player {
  GameNode2D player{"player-node"};
  const float gravity = config::PLAYER_INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = config::PLAYER_JUMP_VELOCITY;
  TileAnimation tileAnimation = {0, config::PLAYER_SPRITE_TOTAL};
  Timer animationTimer{config::PLAYER_ANIMATION_TIME};

  Nebula *nebula = AsyncPointer::get<Nebula>();
  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  TextureLoader *textureLoader = AsyncPointer::get<TextureLoader>();
  Log *log = AsyncPointer::get<Log>();

public:
  Player() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/restart", [this](Event event) { onRestart(); });
    emitter->on("game/update", [this](Event event) { onUpdate(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  };

  void onInit() {
    Rectangle collisionRectangle = {0, 0, config::PLAYER_TILE_WIDTH, config::PLAYER_TILE_HEIGHT};    
    player.getCollisionGeometry().setRaw(collisionRectangle);

    Tile &tile = player.getTile();
    tile.width = config::PLAYER_TILE_WIDTH;
    tile.height = config::PLAYER_TILE_HEIGHT;
    tile.x = 0;
    tile.y = 0;
    tile.setTexture(textureLoader->textures[TEXTURE_SCARFY]);
    player.setPosition(Vector2{config::WINDOW_WIDTH / 2 - tile.width / 2,
                               config::WINDOW_HEIGHT - tile.height});
    log->info("(player) Player initialized.");
  };

  void onRestart() {
    onInit();
    log->info("(player) Player restarted.");
  }

  void onUpdate() {
    if (!gameState->isRunning()) {
      return;
    }

    Tile &tile = player.getTile();    
    Vector2 &position = player.getPosition();    

    if (IsKeyDown(KEY_SPACE) && !isJumping()) {
      velocity = jumpVelocity;
    } else {
      velocity += gravity * GetFrameTime();
    }

    position.y += velocity * GetFrameTime();

    // y borders
    if (position.y < 0) {
      position.y = 0;
    }
    if (position.y > (config::WINDOW_HEIGHT - tile.height)) {
      position.y = config::WINDOW_HEIGHT - tile.height;
    }

    if (!animationTimer.isActive()) {
      if (!isJumping()) {
        tileAnimation.sprite = std::fmod(
            ++tileAnimation.sprite,
            tileAnimation
                .spriteTotal); // 6x1 spritesheet, but with only 60 sprites
        tile.x = tileAnimation.sprite;
      }
      animationTimer.start();
    }
    player.update();
    // if (CheckCollisionRecs(player.getCollisionRec(),
    //                        nebula->getNebula().getCollisionRec())) {
    //   gameState->setGameOver();
    // }
  }

  void onRender() {
    if (!gameState->isStarted()) {
      return;
    }
    player.setColor(gameState->isRunning() ? WHITE : GRAY);
    player.render();
    player.getUpdatedCollisionGeometry().render();        
  }

  bool isJumping() {
    return player.getPosition().y < (config::WINDOW_HEIGHT - player.getTile().height);
  }
};
} // namespace game
