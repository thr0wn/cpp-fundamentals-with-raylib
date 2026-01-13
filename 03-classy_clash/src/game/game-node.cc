#include "game/game-node.h"

namespace game {
GameNode::GameNode(const std::string &name) : _name(name) {
  _id = _idCounter++;
}

std::string &GameNode::name() { return _name; }
const std::string &GameNode::name() const { return _name; }

const uint GameNode::id() const { return _id; }

void GameNode::push(GameNode gameNode) { _children.push_back(gameNode); }
void GameNode::erase(GameNode gameNode) {
  _children.remove_if(
      [gameNode](auto child) { return child.id() == gameNode.id(); });
}

GameNode2D::GameNode2D(const std::string &name) : GameNode(name) {}

Vector2 &GameNode2D::position() { return _position; }
const Vector2 &GameNode2D::position() const { return _position; }

Vector2 &GameNode2D::center() { return _center; }
const Vector2 &GameNode2D::center() const { return _center; }

Geometry &GameNode2D::collisionGeometry() { return _collisionGeometry; }
const Geometry &GameNode2D::collisionGeometry() const {
  return _collisionGeometry;
}

Geometry &GameNode2D::updatedCollisionGeometry() {
  return _updatedCollisionGeometry;
}
const Geometry &GameNode2D::updatedCollisionGeometry() const {
  return _updatedCollisionGeometry;
}

bool GameNode2D::checkCollision(const GameNode2D &other) {
  return _updatedCollisionGeometry.checkCollision(other._updatedCollisionGeometry);
}

void GameNode2D::update() {
  _collisionGeometry.translate(_center, _position, _updatedCollisionGeometry);
}

} // namespace game
