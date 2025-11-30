#pragma once
#include "tile.hpp"

class Entity {
public:
  Tile tile;
  Vector2 position;  
  virtual void start() {};  
  virtual void update() {};  
  virtual void render() {};  
  virtual void stop() {};  
};
