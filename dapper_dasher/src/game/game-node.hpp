#pragma once
#include "tile/tile.hpp"
#include <fmt/format.h>
#include <list>
#include <string>

namespace game {
class GameNode {
private:
  std::string name = "game-node";
  std::list<GameNode> children;

public:
  // Add a new game node
  void addGameNode(GameNode gameNode);
  // Remove a game node
  void removeGameNode(GameNode gameNode);

  // Set game-node name
  void setName(std::string name);
  // Get game-node name
  std::string getName();

  // Inner initialization
  virtual void _start();
  // Inner reinitialization
  virtual void _restart();
  // Inner update logic.
  virtual void _update();
  // Inner render
  virtual void _render();
  // Innerd render out of drawing
  virtual void _renderOut();
  // Inner deinitialization
  virtual void _stop();;
  
  // Initialization
  virtual void restart() {};
  // Reinitialization of game nodes
  virtual void start() {};
  // Update logic.
  virtual void update() {};
  // Do render
  virtual void render() {};
  // Render out of drawing
  virtual void renderOut() {};
  // Deinitialization
  virtual void stop() {};
};

class GameNode2D : public GameNode {
public:
  Tile tile;
  Vector2 position;
};
} // namespace game
