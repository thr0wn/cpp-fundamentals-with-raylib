#pragma once

#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "raylib.h"
#include "texture/texture-loader.h"

namespace game {
class World {
private:
  Color _color{WHITE};
  Texture2D _texture;
  Vector2 _position{0,0};

  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Emitter *_emitter = AsyncPointer::get<Emitter>();
  Log *_log = AsyncPointer::get<Log>();

public:
  World();

  void onAfterInit();
  void onRender2d();
};
}
