#pragma once
#include "game/game-node.hpp"
#include "raylib.h"
#include "tile/tile.hpp"
#include "tile/tile-service.hpp"
#include "game/game-service.hpp"

#define BACKGROUND_FAR_VELOCITY -30.0f;
#define BACKGROUND_MID_VELOCITY -60.0f;
#define BACKGROUND_NEAR_VELOCITY -90.0f;

class Background : public GameNode {
  Texture2D texture;
  const float velocity = BACKGROUND_FAR_VELOCITY;

  Texture2D textureMid;
  const float velocityMid = BACKGROUND_MID_VELOCITY;
  Vector2 positionMid;

  Texture2D textureNear;
  const float velocityNear = BACKGROUND_NEAR_VELOCITY;
  Vector2 positionNear;

  void setBackground(GameTexture gameTexture, Texture2D *texture,
                     Vector2 *position);
  
  void updateTexture(Texture2D texture, Vector2 *position, float velocity);
  void renderTexture(Texture2D texture, Vector2 position, float velocity);  

public:
  void start() override;
  void update() override;
  void render() override;
  void stop() override;
};
