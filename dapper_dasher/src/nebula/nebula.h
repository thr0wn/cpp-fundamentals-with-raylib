#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
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
  GameNode2D nebula{"nebula-node"};
  const float velocity = config::INITIAL_VELOCITY;
  TileAnimation tileAnimation = {0, config::NEBULA_SPRITE_TOTAL,
                                 config::NEBULA_SPRITE_ROW_SIZE};
  Timer animationTimer{config::NEBULA_ANIMATION_TIME};

  GameState *gameState = AsyncPointer::get<GameState>();
  TextureLoader *textureLoader = AsyncPointer::get<TextureLoader>();
  Log *log = AsyncPointer::get<Log>();
  
public:
  Nebula();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender();
};
} // namespace game
