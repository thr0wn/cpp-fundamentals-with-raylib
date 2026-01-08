#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "log/log.h"
#include "game/game-state.h"
#include "raylib.h"
#include "tile/tile.h"
#include "tile/texture-loader.h"

namespace game {
class Background {
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
                     Vector2 *position);

  void updateTexture(Texture2D texture, Vector2 *position, float velocity);
  void renderTexture(Texture2D texture, Vector2 position, float velocity);

public:
  Background();

  void onAfterInit();
  void onUpdate();
  void onRender();
};
} // namespace game
