#include "node/node.h"

namespace game {
Node::Node() {
  _id = _idCounter++;
}

const uint Node::id() const { return _id; }

void Node::addChild(Node node) { _children.push_back(node); }
void Node::removeChild(Node node) {
  _children.remove_if(
      [node](auto child) { return child.id() == node.id(); });
}
} // namespace game
