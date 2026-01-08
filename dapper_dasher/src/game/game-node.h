#pragma once
#include "geometry/geometry.h"
#include "tile/tile.h"
#include <fmt/format.h>
#include <list>
#include <string>
#include <sys/types.h>

namespace game {
class GameNode {
protected:
  inline static uint _idCounter = 0;
  uint _id;
  std::string _name;
  std::list<GameNode> _children;

public:
  GameNode(const std::string &name);

  std::string &name();
  const std::string &name() const;

  const uint id() const;

  void push(GameNode gameNode);
  void erase(GameNode gameNode);

  virtual void update(){};
};

class GameNode2D : public GameNode {
private:
  Tile _tile;
  Vector2 _position{0};
  Vector2 _scale{1, 1};
  Color _color;

  Geometry _collisionGeometry;
  Geometry _updatedCollisionGeometry;

public:
  GameNode2D(const std::string &name);

  Tile &tile();
  const Tile &tile() const;

  Vector2 &position();
  const Vector2 &position() const;

  Vector2 &scale();
  const Vector2 &scale() const;

  Color &color();
  const Color &color() const;

  Geometry &collisionGeometry();
  const Geometry &collisionGeometry() const;

  Geometry &updatedCollisionGeometry();
  const Geometry &updatedCollisionGeometry() const;

  void update();

  void render() const;
};
} // namespace game
