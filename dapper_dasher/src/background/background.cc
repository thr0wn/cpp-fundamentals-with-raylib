#include "background/background.h"

namespace game {
Background::Background() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/restart", [this](Event event) { onInit(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
}

void Background::onInit() {
  setBackground(TEXTURE_FAR_BUILDING, &textureFar, &positionFar);
  setBackground(TEXTURE_BACK_BUILDING, &textureMid, &positionMid);
  setBackground(TEXTURE_NEAR_BUILDING, &textureNear, &positionNear);
  logService->info("(background) Background initialized.");
}

void Background::onUpdate() {
  if (!gameService->isRunning())
    return;
  updateTexture(textureFar, &positionFar, velocityFar);
  updateTexture(textureMid, &positionMid, velocityMid);
  updateTexture(textureNear, &positionNear, velocityNear);
}

void Background::onRender() {
  renderTexture(textureFar, positionFar, velocityFar);
  renderTexture(textureMid, positionMid, velocityMid);
  renderTexture(textureNear, positionNear, velocityNear);
}

void Background::setBackground(GameTexture gameTexture, Texture2D *texture,
                               Vector2 *position) {
  *texture = tileService->textures[gameTexture];
  position->x = 0;
  position->y = 0;
}

void Background::updateTexture(Texture2D texture, Vector2 *position,
                               float velocity) {
  if (position->x <= -3.0f * texture.width) {
    position->x = 0;
  }
  position->x += velocity * GetFrameTime();
}

void Background::renderTexture(Texture2D texture, Vector2 position,
                               float velocity) {
  Color color =
      gameService->isStarted() && !gameService->isPaused() ? WHITE : GRAY;
  Vector2 secondPosition = position;
  secondPosition.x += 3.0f * texture.width;
  DrawTextureEx(texture, position, 0, 3.0f, color);
  DrawTextureEx(texture, secondPosition, 0, 3.0f, color);
}

std::unique_ptr<Background> background;
} // namespace game
