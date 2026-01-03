#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "game/game-node.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raylib.h"
#include "tile/tile.h"
#include "tile/texture-loader.h"
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
  
  GameState *gameState = AsyncPointer::get<GameState>();
  TextureLoader *textureLoader = AsyncPointer::get<TextureLoader>();
  Log *log = AsyncPointer::get<Log>();  

public:
  Player();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender();

  bool isJumping();
};
} // namespace game
