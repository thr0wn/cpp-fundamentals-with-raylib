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
  Vector2 _position{0};

  // collision
  Geometry _collisionGeometry;

public:
  GameNode2D(const std::string &name);

  Vector2 &position();
  const Vector2 &position() const;

  Geometry &collisionGeometry();
  const Geometry &collisionGeometry() const;

  bool checkCollision(const GameNode2D &other);

  void update();
};
} // namespace game
