#include "game/game-node.h"


namespace game {
uint GameNode::idCounter = 0;

GameNode::GameNode(std::string name) : name(name) { id = idCounter++; }

GameNode2D::GameNode2D(std::string name) : GameNode(name) {}

void GameNode::push(GameNode gameNode) { children.push_back(gameNode); }

void GameNode::erase(GameNode gameNode) {
  children.remove_if(
      [gameNode](auto child) { return child.getId() == gameNode.getId(); });
}

void GameNode::setName(std::string name) { this->name = name; }

std::string GameNode::getName() const { return name; }

uint GameNode::getId() const { return id; }

} // namespace game
