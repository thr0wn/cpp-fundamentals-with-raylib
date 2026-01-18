#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raylib.h"
#include "raymath.h"
#include "texture/tile.h"
#include "texture/tile-animation.h"
#include "texture/texture-loader.h"
#include <numbers>
#include "timer/timer.h"
#include "geometry/vector.h"
#include "world/world.h"
#include <cmath>
#include <cstdio>
#include <map>

namespace game {
class Player {
private:
  GameNode2D _player{"player-node"};
  Vector2 _translate{0, 0};  
  float _velocity = config::PLAYER_VELOCITY;
  Camera2D _camera;

  Tile _idleTile{config::PLAYER_TILE_WIDTH, config::PLAYER_TILE_HEIGHT};
  TileAnimation _idleTileAnimation{config::PLAYER_TILE_ANIMATION_IDLE_SIZE};
  Timer _idleAnimationTimer{config::PLAYER_ANIMATION_TIME};

  World *_world = AsyncPointer::get<World>();  
  Emitter *_emitter = AsyncPointer::get<Emitter>();  
  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Log *_log = AsyncPointer::get<Log>();

public:
  Player();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender2d();

  void updatePosition();
  void updateCamera();
  void updateTile();

  const Camera2D &camera() const;  
};
} // namespace game
