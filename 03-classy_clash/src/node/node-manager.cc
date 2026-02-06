#include "node/node-manager.h"

namespace game {
  void NodeManager::addChild(Node *node) { Node::addChild(node); }

  void NodeManager::removeChild(Node *node) { Node::removeChild(node); }

  Geometry *NodeManager::findCollision(Node *node, Geometry *geometryNode) {
    Geometry *gNode = dynamic_cast<Geometry *>(node);
    if (gNode && gNode != geometryNode && gNode->collides(geometryNode)) {
      return gNode;
    }
    return nullptr;  
  }

  Geometry *NodeManager::collides(Geometry *geometryNode) {
    Node *foundNode = Node::traverse(this, [this, geometryNode](Node *node) {
      return this->findCollision(node, geometryNode);
    });
    if (foundNode) {
      return dynamic_cast<Geometry *>(foundNode);    
    }    
    return nullptr;
  };

  void NodeManager::update() { Node::update(); }

  void NodeManager::prepareRender() {
    for(auto it = nodes.begin(); it != nodes.end(); ++it) {
      auto list = it->second;
      list.clear();
    }
  }

  Node *NodeManager::traverseSort(Node *node) {
    Node2D *node2D = dynamic_cast<Node2D *>(node);
    if (node2D) {
      auto &list = nodes[node2D->getLayer()];
      list.push_back(node2D);
    }
    return nullptr;
  }

  void NodeManager::doRender() {
    for(auto it = nodes.begin(); it != nodes.end(); ++it) {
      auto &list = it->second;
      for(auto listIt = list.begin(); listIt != list.end(); ++listIt) {
        auto &node2D = *listIt;
        if (node2D->isEnabled()) {
          node2D->render();
        }
      }
    }
  }

  void NodeManager::render() {
    prepareRender();
    Node::traverse(this, [this](Node *node) { return this->traverseSort(node); });
    doRender();
  }
}; // namespace game
