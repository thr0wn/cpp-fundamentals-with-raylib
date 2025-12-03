#pragma once
#include "tile/tile.hpp"

class GameNode {
public:
  Vector2 position;  
  virtual void start() {};  
  virtual void update() {};  
  virtual void render() {};  
  virtual void renderOut() {};  
  virtual void stop() {};  
};

class GameNode2D: public GameNode {
public:
  Tile tile;
};
