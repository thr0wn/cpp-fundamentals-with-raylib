#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raylib.h"
#include "tile/texture-loader.h"
#include "tile/tile.h"

namespace game {
class Background {
private:
  Texture2D textureFar;
  const float velocityFar = config::BACKGROUND_FAR_VELOCITY;
  Vector2 positionFar;

  Texture2D textureMid;
  const float velocityMid = config::BACKGROUND_MID_VELOCITY;
  Vector2 positionMid;

  Texture2D textureNear;
  const float velocityNear = config::BACKGROUND_NEAR_VELOCITY;
  Vector2 positionNear;

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  TextureLoader *textureLoader = AsyncPointer::get<TextureLoader>();
  Log *log = AsyncPointer::get<Log>();

  void setBackground(GameTexture gameTexture, Texture2D *texture,
                     Vector2 *position) {
    *texture = textureLoader->textures[gameTexture];
    position->x = 0;
    position->y = 0;
  }

  void updateTexture(Texture2D texture, Vector2 *position, float velocity) {
    if (position->x <= -3.0f * texture.width) {
      position->x = 0;
    }
    position->x += velocity * GetFrameTime();
  }

  void renderTexture(Texture2D texture, Vector2 position, float velocity) {
    Color color = gameState->isRunning() ? WHITE : GRAY;
    Vector2 secondPosition = position;
    secondPosition.x += 3.0f * texture.width;
    DrawTextureEx(texture, position, 0, 3.0f, color);
    DrawTextureEx(texture, secondPosition, 0, 3.0f, color);
  }

  void onAfterInit() {
    setBackground(TEXTURE_FAR_BUILDING, &textureFar, &positionFar);
    setBackground(TEXTURE_BACK_BUILDING, &textureMid, &positionMid);
    setBackground(TEXTURE_NEAR_BUILDING, &textureNear, &positionNear);
    log->info("(background) Background initialized.");
  }

  void onUpdate() {
    if (!gameState->isRunning())
      return;
    updateTexture(textureFar, &positionFar, velocityFar);
    updateTexture(textureMid, &positionMid, velocityMid);
    updateTexture(textureNear, &positionNear, velocityNear);
  }

  void onRender() {
    renderTexture(textureFar, positionFar, velocityFar);
    renderTexture(textureMid, positionMid, velocityMid);
    renderTexture(textureNear, positionNear, velocityNear);
  }

public:
  Background() {
    emitter->on("game/init:after", [this](Event event) { onAfterInit(); });
    emitter->on("game/restart", [this](Event event) { onAfterInit(); });
    emitter->on("game/update", [this](Event event) { onUpdate(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  }
};
} // namespace game
