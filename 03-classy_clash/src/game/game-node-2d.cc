#include "game/game-node-2d.h"

namespace game {
GameNode2D::GameNode2D() : GameNode() {}

Vector2 &GameNode2D::position() { return _position; }
const Vector2 &GameNode2D::position() const { return _position; }

Tile *&GameNode2D::tile() { return _tile; };
const Tile *const GameNode2D::tile() const { return _tile; };

Geometry *&GameNode2D::geometry() { return _geometry; }
const Geometry *const GameNode2D::geometry() const { return _geometry; }

bool &GameNode2D::debug() { return _debug; }
const bool &GameNode2D::debug() const { return _debug; }

bool GameNode2D::checkCollision(const GameNode2D &other) {
  if (_geometry && other._geometry) {
    return _geometry->checkCollision(*other._geometry);
  }
  return false;
}

void GameNode2D::update() {
  if (_tile) {
    vector::copy(_position, _tile->position());
    _tile->rotation() = _rotation;
    _tile->update();
  }
  if (_geometry) {
    vector::copy(_position, _geometry->position());
    _geometry->rotation() = _rotation;
    _geometry->update();
  }
}

void GameNode2D::render() const {
  if (_tile) {
    _tile->render();
  }
  if (_debug && _geometry) {
    _geometry->render();
  }
}

} // namespace game
