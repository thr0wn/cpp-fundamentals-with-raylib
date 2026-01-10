#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raylib.h"
#include "tile/tile.h"
#include "tile/texture-loader.h"
#include "timer/timer.h"
#include <cmath>
#include <map>

namespace game {
class Nebula {
private:  
  GameNode2D _nebula{"nebula-node"};  
  const float _velocity = config::INITIAL_VELOCITY;
  TileAnimation _tileAnimation{config::NEBULA_SPRITE_TOTAL,
                                 config::NEBULA_SPRITE_ROW_SIZE};
  Timer _animationTimer{config::NEBULA_ANIMATION_TIME};

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Log *_log = AsyncPointer::get<Log>();
  
public:
  Nebula();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender();

  const GameNode2D& nebula() const;  
};
} // namespace game
