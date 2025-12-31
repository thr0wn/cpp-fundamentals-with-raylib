#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-emitter.h"
#include "game/game-service.h"
#include "raylib.h"
#include "tile/tile-service.h"
#include "tile/tile.h"
#include "timer/schedule-service.h"
#include "player/player-score.h"
#include "timer/timer.h"
#include <cmath>
#include <cstdio>

namespace game {
class Player {
  GameNode2D player{"player-node"};
  const float gravity = config::PLAYER_INITIAL_GRAVITY;
  float velocity = 0;
  const float jumpVelocity = config::PLAYER_JUMP_VELOCITY;
  TileAnimation tileAnimation = {0, config::PLAYER_SPRITE_TOTAL};
  PlayerScore playerScore;

public:
  Player();

  void onInit();
  void onRestart();
  void onUpdate();
  void onRender();

  bool isJumping();
};
} // namespace game
