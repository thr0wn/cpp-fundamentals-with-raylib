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

Geometry &GameNode2D::collisionGeometry() { return _collisionGeometry; }
const Geometry &GameNode2D::collisionGeometry() const {
  return _collisionGeometry;
}

bool GameNode2D::checkCollision(const GameNode2D &other) {
  return _collisionGeometry.checkCollision(other._collisionGeometry);
}

void GameNode2D::update() {
  vector::copy(_position, _collisionGeometry.position());  
  _collisionGeometry.update();
}

} // namespace game
