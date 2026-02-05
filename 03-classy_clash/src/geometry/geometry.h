#pragma once

#include "node/node-2d.h"
#include "raylib.h"
#include <iostream>
#include <variant>

namespace game {
typedef struct Point {
  struct Vector2;
} Point;

typedef struct Line {
  Vector2 point1;
  Vector2 point2;
} Line;

typedef struct Triangle {
  Vector2 point1;
  Vector2 point2;
  Vector2 point3;
} Triangle;

typedef struct Circle {
  Vector2 center;
  float radius;
} Circle;

typedef struct Sphere {
  Vector3 center;
  float radius;
} Sphere;

typedef struct Poly {
  Vector3 *points;
  int pointCount;
} Poly;

typedef std::variant<Rectangle*, Circle*, Triangle*, Poly*, Line*, BoundingBox*, Sphere*>
    RawGeometry;
typedef enum GeometryOrigin {
  GEOMETRY_ORIGIN_TOP_LEFT = 0,
  GEOMETRY_ORIGIN_CENTER
} GeometryOrigin;

class Geometry: public Node2D {
private:
  RawGeometry _raw;
  GeometryOrigin _originType;

public:
  Geometry();
  Geometry(RawGeometry raw);
  
  RawGeometry &raw();
  const RawGeometry &raw() const;

  GeometryOrigin &originType();
  const GeometryOrigin &originType() const;

  bool collides(const Geometry &other) const;
  void update() override;
  void render() const override;
};
} // namespace game
