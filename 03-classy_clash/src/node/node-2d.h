#pragma once

#include <fmt/format.h>
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

  uint _layer = 0; 
public:
  Node2D();

  void setPosition(const Vector2 &position);
  const Vector2 &getPosition() const;

  void setLocalPosition(const Vector2 &localPosition);
  const Vector2 &getLocalPosition() const;

  const Vector2 &getWorldPosition() const;
  
  void setRotation(float rotation);
  float getRotation() const;

  void setLocalRotation(float localRotation);
  float getLocalRotation() const;

  float getWorldRotation() const;

  void setOrigin(const Vector2 &origin);
  const Vector2 &getOrigin() const;

  void setLayer(uint layer);
  uint getLayer() const;

  void update() override;
};
} // namespace game
