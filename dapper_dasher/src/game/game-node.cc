#include "game/game-node.h"


namespace game {
uint GameNode::idCounter = 0;

GameNode::GameNode(std::string name) : name(name) { id = idCounter++; }

void GameNode::push(GameNode gameNode) { children.push_back(gameNode); }

void GameNode::erase(GameNode gameNode) {
  children.remove_if(
      [gameNode](auto child) { return child.getId() == gameNode.getId(); });
}

void GameNode::setName(std::string name) { this->name = name; }

std::string GameNode::getName() const { return name; }

uint GameNode::getId() const { return id; }


GameNode2D::GameNode2D(std::string name) : GameNode(name) {}

const Rectangle &GameNode2D::getCollisionRec() {
  collisionRec.x = position.x;  
  collisionRec.x = position.x;  
  collisionRec.width = tile.width * scale.x;
  collisionRec.height = tile.height * scale.y;
  return collisionRec;
}

void GameNode2D::draw() {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width * scale.x, tile.height * scale.y};
  Vector2 origin = {0, 0};
  DrawTexturePro(tile.texture, source, destiny, origin, 0.0f, color);
}

} // namespace game
