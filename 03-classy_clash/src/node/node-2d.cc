#include "node/node-2d.h"

namespace game {
Node2D::Node2D() : Node() {}

void Node2D::setPosition(const Vector2 &position) {
  vector::copy(position, _position);
}
const Vector2 &Node2D::getPosition() const { return _position; }

void Node2D::setLocalPosition(const Vector2 &localPosition) {
  vector::copy(localPosition, _position);
}
const Vector2 &Node2D::getLocalPosition() const { return _localPosition; }

const Vector2 &Node2D::getWorldPosition() const { return _worldPosition; }

void Node2D::setRotation(float rotation) { _rotation = rotation; }
float Node2D::getRotation() const { return _rotation; }

void Node2D::setLocalRotation(float rotation) { _rotation = rotation; }
float Node2D::getLocalRotation() const { return _rotation; }

float Node2D::getWorldRotation() const { return _worldRotation; }

void Node2D::setOrigin(const Vector2 &origin) { vector::copy(origin, _origin); }
const Vector2 &Node2D::getOrigin() const { return _origin; }

void Node2D::setLayer(uint layer) { _layer = layer; }
uint Node2D::getLayer() const { return _layer; }

void Node2D::update() {
  vector::copy(Vector2Add(_position, _localPosition), _worldPosition);
  _worldRotation = _rotation + _localRotation;
  for (auto &child : _children) {
    Node2D *child2d = dynamic_cast<Node2D *>(child);
    if (child2d) {
      child2d->setPosition(_position);
    }
    child->update();
  }
}
} // namespace game
