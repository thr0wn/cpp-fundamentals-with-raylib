#pragma once
#include "geometry/geometry.h"
#include "geometry/vector.h"
#include "texture/tile.h"
#include <fmt/format.h>
#include <string>
#include "game-node.h"

namespace game {
class GameNode2D : public GameNode {
private:
  Vector2 _position = Vector2{0};
  float _rotation = 0;  
  Tile *_tile;
  Geometry *_geometry;
  bool _debug;

public:
  GameNode2D();

  Vector2 &position();
  const Vector2 &position() const;

  float &rotation();
  const float &rotation() const;

  Tile *&tile();
  const Tile * const tile() const;

  Geometry *&geometry();
  const Geometry * const geometry() const;

  bool &debug();
  const bool &debug() const;

  bool checkCollision(const GameNode2D &other);
  void update();
  void render() const;  
};
} // namespace game
