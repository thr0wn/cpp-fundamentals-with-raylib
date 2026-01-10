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
private:  
  Texture2D _textureFar;
  const float _velocityFar = config::BACKGROUND_FAR_VELOCITY;
  Vector2 _positionFar;
  
  Texture2D _textureMid;
  const float _velocityMid = config::BACKGROUND_MID_VELOCITY;
  Vector2 _positionMid;

  Texture2D _textureNear;
  const float _velocityNear = config::BACKGROUND_NEAR_VELOCITY;
  Vector2 _positionNear;

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Log *_log = AsyncPointer::get<Log>();

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
