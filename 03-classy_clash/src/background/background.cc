#include "background/background.h"

namespace game {
Background::Background() {
  _emitter->on("game/init:after", [this](Event event) { onAfterInit(); });
  _emitter->on("game/restart", [this](Event event) { onAfterInit(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
}

void Background::onAfterInit() {
  setBackground(TEXTURE_FAR_BUILDING, &_textureFar, &_positionFar);
  setBackground(TEXTURE_BACK_BUILDING, &_textureMid, &_positionMid);
  setBackground(TEXTURE_NEAR_BUILDING, &_textureNear, &_positionNear);
  _log->info("(background) Background initialized.");
}

void Background::onUpdate() {
  if (!_gameState->running())
    return;
  updateTexture(_textureFar, &_positionFar, _velocityFar);
  updateTexture(_textureMid, &_positionMid, _velocityMid);
  updateTexture(_textureNear, &_positionNear, _velocityNear);
}

void Background::onRender() {
  renderTexture(_textureFar, _positionFar, _velocityFar);
  renderTexture(_textureMid, _positionMid, _velocityMid);
  renderTexture(_textureNear, _positionNear, _velocityNear);
}

void Background::setBackground(GameTexture gameTexture, Texture2D *texture,
                               Vector2 *position) {
  *texture = _textureLoader->textures()[gameTexture];
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
  Color color = _gameState->running() ? WHITE : GRAY;
  Vector2 secondPosition = position;
  secondPosition.x += 3.0f * texture.width;
  DrawTextureEx(texture, position, 0, 3.0f, color);
  DrawTextureEx(texture, secondPosition, 0, 3.0f, color);
}
} // namespace game
