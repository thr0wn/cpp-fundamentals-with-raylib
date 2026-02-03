#pragma once

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
typedef enum GeometryPivot {
  GEOMETRY_PIVOT_TOP_LEFT = 0,
  GEOMETRY_PIVOT_CENTER
} GeometryPivot;
class Geometry {
private:
  RawGeometry _raw;
  GeometryPivot _pivot;
  Vector2 _origin = Vector2{0};
  Vector2 _position = Vector2{0};
  float _rotation = 0;

public:
  Geometry();
  Geometry(RawGeometry raw);
  
  RawGeometry &raw();
  const RawGeometry &raw() const;

  GeometryPivot &pivot();
  const GeometryPivot &pivot() const;

  Vector2 &origin();
  const Vector2 &origin() const;
  
  Vector2 &position();
  const Vector2 &position() const;

  float &rotation();
  const float &rotation() const;  

  bool checkCollision(const Geometry &other) const;
  void update() const;
  void render() const;
};
} // namespace game
