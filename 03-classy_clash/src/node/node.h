#pragma once
#include "geometry/geometry.h"
#include "geometry/vector.h"
#include "texture/tile.h"
#include <fmt/format.h>
#include <list>
#include <string>
#include <sys/types.h>

namespace game {
class Node {
protected:
  inline static uint _idCounter = 0;
  uint _id;
  std::list<Node> _children;

public:
  Node();

  const uint id() const;

  void addChild(Node node);
  void removeChild(Node node);

  virtual void update(){};
};
} // namespace game
