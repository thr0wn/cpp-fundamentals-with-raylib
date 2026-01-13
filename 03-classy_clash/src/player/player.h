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
#include <cstdio>
#include <map>

namespace game {
class Player {
private:  
  GameNode2D _player{"player-node"};
  const float _gravity = config::PLAYER_INITIAL_GRAVITY;
  float _velocity = 0;
  const float _jumpVelocity = config::PLAYER_JUMP_VELOCITY;

  Tile _tile{Rectangle{0, 0 ,config::PLAYER_TILE_WIDTH, config::PLAYER_TILE_HEIGHT}};  
  TileAnimation _tileAnimation{config::PLAYER_SPRITE_TOTAL};
  Timer _animationTimer{config::PLAYER_ANIMATION_TIME};

  Emitter *_emitter = AsyncPointer::get<Emitter>();  
  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Log *_log = AsyncPointer::get<Log>();

public:
  Player();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender();

  bool jumping();
};
} // namespace game
