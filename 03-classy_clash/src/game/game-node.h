#pragma once
#include "geometry/geometry.h"
#include "geometry/vector.h"
#include "texture/tile.h"
#include <fmt/format.h>
#include <list>
#include <string>
#include <sys/types.h>

namespace game {
class GameNode {
protected:
  inline static uint _idCounter = 0;
  uint _id;
  std::list<GameNode> _children;

public:
  GameNode();

  const uint id() const;

  void add(GameNode gameNode);
  void remove(GameNode gameNode);

  virtual void update(){};
};
} // namespace game
