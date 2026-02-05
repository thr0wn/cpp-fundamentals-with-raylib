#pragma once

#include "geometry/vector.h"
#include <fmt/format.h>
#include <string>
#include "node/node.h"
#include "raymath.h"

namespace game {
class Node2D : public Node {
protected:
  Vector2 _position = Vector2{0};
  Vector2 _localPosition = Vector2{0};
  Vector2 _worldPosition = Vector2{0};
  float _rotation = 0;
  float _localRotation = 0;
  float _worldRotation = 0;

  Vector2 _origin = Vector2{0};
public:
  Node2D();

  Vector2 &position();
  const Vector2 &position() const;

  Vector2 &localPosition();
  const Vector2 &localPosition() const;

  const Vector2 &worldPosition() const;
  
  float &rotation();
  const float &rotation() const;

  float &localRotation();
  const float &localRotation() const;

  const float &worldRotation() const;

  Vector2 &origin();
  const Vector2 &origin() const;

  void update() override;
};
} // namespace game
