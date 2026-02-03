#include "game/game-node.h"

namespace game {
GameNode::GameNode() {
  _id = _idCounter++;
}

const uint GameNode::id() const { return _id; }

void GameNode::add(GameNode gameNode) { _children.push_back(gameNode); }
void GameNode::remove(GameNode gameNode) {
  _children.remove_if(
      [gameNode](auto child) { return child.id() == gameNode.id(); });
}
} // namespace game
