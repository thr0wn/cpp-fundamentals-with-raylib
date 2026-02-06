#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "node/node-2d.h"
#include "game/game-state.h"
#include "geometry/geometry.h"
#include "geometry/vector.h"
#include "log/log.h"
#include "node/node-manager.h"
#include "raylib.h"
#include "raymath.h"
#include "texture/texture-loader.h"
#include "texture/tile-animation.h"
#include "texture/tile.h"
#include <cmath>
#include <cstdio>
#include <map>
#include <numbers>

namespace game {
class Player {
private:
  NodeManager _nodeManager;
  Node2D _player;
  Vector2 _translate{0, 0};
  float _velocity = config::PLAYER_VELOCITY;
  Camera2D _camera;

  Tile _tile{config::PLAYER_TILE_WIDTH, config::PLAYER_TILE_HEIGHT};
  TileAnimation _tileAnimation{config::PLAYER_TILE_ANIMATION_IDLE_SIZE};
  Timer _animationTimer{config::PLAYER_ANIMATION_TIME};

  Rectangle _collisionRectangle =
      Rectangle{0, 0, 0.5f * config::PLAYER_TILE_WIDTH,
                0.5f * config::PLAYER_TILE_HEIGHT};
  Geometry _collisionGeometry{&_collisionRectangle};  

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  GameState *_gameState = AsyncPointer::get<GameState>();
  TextureLoader *_textureLoader = AsyncPointer::get<TextureLoader>();
  Log *_log = AsyncPointer::get<Log>();

public:
  Player();

  const Camera2D &camera() const;

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender2d();

  void updateTranslate();
  void updateCamera();
  void updateTile();
  void updateNode();

};
} // namespace game
