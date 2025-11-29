#pragma once
#include "tile.hpp"

class Entity {
public:
  Tile tile;  
  virtual void start() = 0;  
  virtual void update() = 0;  
  virtual void render() = 0;  
  virtual void stop() = 0;  
};
