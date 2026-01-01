#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-state.h"
#include "raylib.h"
#include "tile/tile.h"
#include "timer/schedule-service.h"
#include "timer/timer.h"
#include <cmath>
#include <map>

namespace game {
class Nebula {
  GameNode2D nebula{"nebula-node"};
  const float velocity = config::INITIAL_VELOCITY;
  TileAnimation tileAnimation = {0, config::NEBULA_SPRITE_TOTAL,
                                 config::NEBULA_SPRITE_ROW_SIZE};
  GameState *gameState;
  
public:
  Nebula();

  void onInit();
  void onAfterInit();
  void onRestart();
  void onUpdate();
  void onRender();
};
} // namespace game
