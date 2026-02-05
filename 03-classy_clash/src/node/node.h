#pragma once
#include "geometry/vector.h"
#include <fmt/format.h>
#include <list>
#include <string>

namespace game {
class Node {
protected:
  inline static uint _idCounter = 0;
  uint _id;
  std::list<Node*> _children;
  bool _enabled = true;
  
public:
  Node();

  const uint id() const;
  
  const std::list<Node*> children() const;

  bool &enabled();
  const bool &enabled() const;
  
  void addChild(Node *node);
  void removeChild(Node *node);

  virtual void update();
  virtual void render() const;
};
} // namespace game
