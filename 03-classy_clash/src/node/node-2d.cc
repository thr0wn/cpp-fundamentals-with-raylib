#include "node/node-2d.h"

namespace game {
Node2D::Node2D() : Node() {}

Vector2 &Node2D::position() { return _position; }
const Vector2 &Node2D::position() const { return _position; }

Tile *&Node2D::tile() { return _tile; };
const Tile *const Node2D::tile() const { return _tile; };

Geometry *&Node2D::geometry() { return _geometry; }
const Geometry *const Node2D::geometry() const { return _geometry; }

bool &Node2D::debug() { return _debug; }
const bool &Node2D::debug() const { return _debug; }

bool Node2D::checkCollision(const Node2D &other) {
  if (_geometry && other._geometry) {
    return _geometry->checkCollision(*other._geometry);
  }
  return false;
}

void Node2D::update() {
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

void Node2D::render() const {
  if (_tile) {
    _tile->render();
  }
  if (_debug && _geometry) {
    _geometry->render();
  }
}

} // namespace game
