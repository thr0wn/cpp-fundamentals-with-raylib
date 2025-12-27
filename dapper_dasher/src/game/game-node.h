#pragma once
#include "tile/tile.h"
#include <fmt/format.h>
#include <list>
#include <string>
#include <sys/types.h>

namespace game {
class GameNode {
private:
  static uint idCounter;
  uint id;  
  std::string name;
  std::list<GameNode> children;

public:
  GameNode(std::string name);

  // Add a new game node
  void push(GameNode gameNode);
  // Remove a game node
  void erase(GameNode gameNode);

  // set game-node name
  void setName(std::string name);
  // Get game-node name
  std::string getName() const;
  // Get game-node id
  uint getId() const;
};

class GameNode2D : public GameNode {
public:
  GameNode2D(std::string name);
  
  Tile tile;
  Vector2 position;
};
} // namespace game
