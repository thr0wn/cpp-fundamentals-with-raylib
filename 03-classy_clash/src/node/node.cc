#include "node/node.h"

namespace game {
Node::Node() { _id = _idCounter++; }

uint Node::getId() const { return _id; }

const std::list<Node *> Node::getChildren() const { return _children; };

void Node::setEnabled(bool enabled) { _enabled = enabled; }
bool Node::isEnabled() const { return _enabled; }

void Node::addChild(Node *node) { _children.push_back(node); }
void Node::removeChild(Node *node) { _children.remove(node); }

void Node::update() {
  for (auto &child : _children) {
    child->update();
  }
}
void Node::render() {
  for (auto &child : _children) {
    if (child->isEnabled()) {
      child->render();
    }
  }
}

Node *Node::traverse(Node *node, TraverseFunc func) {
  Node *foundNode = func(node);
  if (foundNode) {
    return foundNode;    
  }
  for (Node *child : node->getChildren()) {
    Node *foundNode = traverse(child, func);
    if (foundNode) {
      return foundNode;    
    }
  }
  return nullptr;  
}

bool operator==(const Node &lhs, const Node &rhs) {
  return lhs.getId() == rhs.getId();
}

bool operator!=(const Node &lhs, const Node &rhs) { return lhs == rhs; }

} // namespace game
