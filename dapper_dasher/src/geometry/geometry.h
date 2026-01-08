#pragma once

#include "raylib.h"
#include <iostream>
#include <variant>

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

namespace game {
typedef std::variant<Rectangle, Circle, Triangle, Poly, Line, BoundingBox,
                     Sphere>
    RawGeometry;
typedef enum GeometryPivot {
  GEOMETRY_PIVOT_TOP_LEFT = 0,
  GEOMETRY_PIVOT_CENTER
} GeometryPivot;
class Geometry {
private:
  RawGeometry _raw;
  GeometryPivot _pivot;
  
public:
  RawGeometry &raw();
  const RawGeometry &raw() const;

  GeometryPivot &pivot();
  const GeometryPivot &pivot() const;  

  bool checkCollision(const Geometry &other) const;
  void translate(const Vector2 &center, const Vector2 &translation, Geometry &out) const;
  void render() const;
};
} // namespace game
