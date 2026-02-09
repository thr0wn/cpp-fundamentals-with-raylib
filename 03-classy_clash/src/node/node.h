#pragma once
#include "geometry/vector.h"
#include <fmt/format.h>
#include <functional>
#include <list>
#include <string>

namespace game {
  class Node {
    typedef std::function<Node*(Node *)> TraverseFunc;
  
  protected:
    inline static uint _idCounter = 0;
    uint _id;
    std::list<Node *> _children;
    bool _enabled = true;

  public:
    Node();

    uint getId() const;

    const std::list<Node *> getChildren() const;

    void setEnabled(bool enabled);
    bool isEnabled() const;

    virtual void addChild(Node *node);
    virtual void removeChild(Node *node);

    virtual void update();
    virtual void render();
  
    static Node *traverse(Node* node, TraverseFunc func);

    friend bool operator==(const Node &lhs, const Node &rhs);
    friend bool operator!=(const Node &lhs, const Node &rhs);
  };
} // namespace game
