#include "node/node.h"

namespace game {
Node::Node() { _id = _idCounter++; }

const uint Node::id() const { return _id; }

const std::list<Node*> Node::children() const { return _children; };

bool &Node::enabled() { return _enabled; }
const bool &Node::enabled() const { return _enabled; }

void Node::addChild(Node *node) { _children.push_back(node); }
void Node::removeChild(Node *node) {
  _children.remove_if([node](auto child) { return child->id() == node->id(); });
}

void Node::update() {
  for (auto &child : _children) {
    child->update();
  }
}
void Node::render() const {
  for (auto &child : _children) {
    if (child->enabled()) {
      child->render();
    }
  }
}
} // namespace game
