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

Tile &GameNode2D::tile() { return _tile; }
const Tile &GameNode2D::tile() const { return _tile; }

Vector2 &GameNode2D::position() { return _position; }
const Vector2 &GameNode2D::position() const { return _position; }

Vector2 &GameNode2D::scale() { return _scale; }
const Vector2 &GameNode2D::scale() const { return _scale; }

Color &GameNode2D::color() { return _color; }
const Color &GameNode2D::color() const { return _color; }

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
  _center.x = _scale.x * _tile.width/2;
  _center.y = _scale.y * _tile.height/2;
  _collisionGeometry.translate(_center, _position, _updatedCollisionGeometry);
}

void GameNode2D::render() const {
  Rectangle source = {(_tile.x * _tile.width), (_tile.y * _tile.height),
                      _tile.width, _tile.height};
  Rectangle destiny = {_position.x, _position.y, _tile.width * _scale.x,
                       _tile.height * _scale.y};
  Vector2 origin = {0, 0};
  DrawTexturePro(_tile.texture(), source, destiny, origin, 0.0f, _color);
}

} // namespace game
