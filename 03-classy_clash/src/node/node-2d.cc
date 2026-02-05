#include "node/node-2d.h"

namespace game {
Node2D::Node2D() : Node() {}

Vector2 &Node2D::position() { return _position; }
const Vector2 &Node2D::position() const { return _position; }

Vector2 &Node2D::localPosition() { return _localPosition; }
const Vector2 &Node2D::localPosition() const { return _localPosition; }

const Vector2 &Node2D::worldPosition() const { return _worldPosition; }

float &Node2D::rotation() { return _rotation; }
const float &Node2D::rotation() const { return _rotation; }

float &Node2D::localRotation() { return _localRotation; }
const float &Node2D::localRotation() const { return _localRotation; }

const float &Node2D::worldRotation() const { return _worldRotation; }

Vector2 &Node2D::origin() { return _origin; }
const Vector2 &Node2D::origin() const { return _origin; }

void Node2D::update() {
  vector::copy(Vector2Add(_position, _localPosition), _worldPosition);
  _worldRotation = _rotation + _localRotation;
  for (auto &child : _children) {
    Node2D *child2d = static_cast<Node2D *>(child);
    if (child2d) {
      vector::copy(_position, child2d->position());
    }
    child->update();
  }
}

} // namespace game
