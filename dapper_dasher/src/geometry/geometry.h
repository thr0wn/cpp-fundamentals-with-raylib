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
                     Sphere> RawGeometry;
class Geometry {
private:
  RawGeometry raw;

public:
  void setRaw(const RawGeometry &raw) { this->raw = raw; }
  const RawGeometry &getRaw() const { return raw; }

  bool checkCollision(const Geometry &other) const {
    if (std::holds_alternative<Rectangle>(raw) &&
        std::holds_alternative<Rectangle>(other.raw)) {
      const Rectangle &rectangle = std::get<Rectangle>(raw);
      const Rectangle &rectangleOther = std::get<Rectangle>(other.raw);
      return CheckCollisionRecs(rectangle, rectangleOther);
    } else if (std::holds_alternative<Rectangle>(raw) &&
               std::holds_alternative<Circle>(other.raw)) {
      const Rectangle &rectangle = std::get<Rectangle>(raw);
      const Circle &circle = std::get<Circle>(other.raw);
      return CheckCollisionCircleRec(circle.center, circle.radius, rectangle);
    } else if (std::holds_alternative<Circle>(raw) &&
               std::holds_alternative<Rectangle>(other.raw)) {
      const Circle &circle = std::get<Circle>(raw);
      const Rectangle &rectangle = std::get<Rectangle>(other.raw);
      return CheckCollisionCircleRec(circle.center, circle.radius, rectangle);
    } else if (std::holds_alternative<Circle>(raw) &&
               std::holds_alternative<Circle>(other.raw)) {
      const Circle &circle = std::get<Circle>(raw);
      const Circle &circleOther = std::get<Circle>(other.raw);
      return CheckCollisionCircles(circle.center, circle.radius,
                                   circleOther.center, circle.radius);
    }
    std::cout << "GAMEINFO: (geometry) checkCollision not implemented!!!\n";
    return false;
  }

  void translate(const Vector2 &translation, Geometry &out) const {
    if (std::holds_alternative<Rectangle>(raw)) {
      if (!std::holds_alternative<Rectangle>(out.raw)) {
        out.raw = std::get<Rectangle>(raw);
      }
      const Rectangle &rec = std::get<Rectangle>(raw);
      Rectangle &recOut = std::get<Rectangle>(out.raw);
      recOut.x = rec.x + translation.x;
      recOut.y = rec.y + translation.y;
      recOut.width = rec.width;
      recOut.height = rec.height;      
    } else if (std::holds_alternative<Circle>(raw)) {
      if (!std::holds_alternative<Circle>(out.raw)) {
        out.raw = std::get<Circle>(raw);
      }
      const Circle &circle = std::get<Circle>(raw);
      Circle &circleOut = std::get<Circle>(out.raw);
      circleOut.center.x = circle.center.x + translation.x;
      circleOut.center.y = circle.center.y + translation.y;
      circleOut.radius = circle.radius;      
    } else {
      std::cout << "GAMEINFO: (geometry) translate not implemented!!!\n";
    }
  }

  void render() const {
    if (std::holds_alternative<Rectangle>(raw)) {
      const Rectangle &rec = std::get<Rectangle>(raw);
      DrawRectangleLinesEx(rec, 1.0, GREEN);
    } else if (std::holds_alternative<Circle>(raw)) {
      const Circle &circle = std::get<Circle>(raw);
      DrawCircleLinesV(circle.center, circle.radius, GREEN);
    } else {
      std::cout << "GAMEINFO: (geometry) draw not implemented!!!\n";
    }
  }
};
} // namespace game
