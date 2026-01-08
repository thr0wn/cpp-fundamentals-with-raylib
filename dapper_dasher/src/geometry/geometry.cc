#include "geometry/geometry.h"

namespace game {
RawGeometry &Geometry::raw() { return _raw; }
const RawGeometry &Geometry::raw() const { return _raw; }

GeometryPivot &Geometry::pivot() { return _pivot; }
const GeometryPivot &Geometry::pivot() const { return _pivot; }

bool Geometry::checkCollision(const Geometry &other) const {
  if (std::holds_alternative<Rectangle>(_raw) &&
      std::holds_alternative<Rectangle>(other._raw)) {
    const Rectangle &rectangle = std::get<Rectangle>(_raw);
    const Rectangle &rectangleOther = std::get<Rectangle>(other._raw);
    return CheckCollisionRecs(rectangle, rectangleOther);
  } else if (std::holds_alternative<Rectangle>(_raw) &&
             std::holds_alternative<Circle>(other._raw)) {
    const Rectangle &rectangle = std::get<Rectangle>(_raw);
    const Circle &circle = std::get<Circle>(other._raw);
    return CheckCollisionCircleRec(circle.center, circle.radius, rectangle);
  } else if (std::holds_alternative<Circle>(_raw) &&
             std::holds_alternative<Rectangle>(other._raw)) {
    const Circle &circle = std::get<Circle>(_raw);
    const Rectangle &rectangle = std::get<Rectangle>(other._raw);
    return CheckCollisionCircleRec(circle.center, circle.radius, rectangle);
  } else if (std::holds_alternative<Circle>(_raw) &&
             std::holds_alternative<Circle>(other._raw)) {
    const Circle &circle = std::get<Circle>(_raw);
    const Circle &circleOther = std::get<Circle>(other._raw);
    return CheckCollisionCircles(circle.center, circle.radius,
                                 circleOther.center, circle.radius);
  }
  std::cout << "GAMEINFO: (geometry) checkCollision not implemented!!!\n";
  return false;
}

void Geometry::translate(const Vector2 &center, const Vector2 &translation,
                         Geometry &out) const {
  if (std::holds_alternative<Rectangle>(_raw)) {
    if (!std::holds_alternative<Rectangle>(out._raw)) {
      out._raw = std::get<Rectangle>(_raw);
    }
    const Rectangle &rec = std::get<Rectangle>(_raw);
    Rectangle &recOut = std::get<Rectangle>(out._raw);
    recOut.x = rec.x + translation.x;
    recOut.y = rec.y + translation.y;
    recOut.width = rec.width;
    recOut.height = rec.height;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      recOut.x += center.x - recOut.width / 2;
      recOut.y += center.y - recOut.height / 2;
    }
  } else if (std::holds_alternative<Circle>(_raw)) {
    if (!std::holds_alternative<Circle>(out._raw)) {
      out._raw = std::get<Circle>(_raw);
    }
    const Circle &circle = std::get<Circle>(_raw);
    Circle &circleOut = std::get<Circle>(out._raw);
    circleOut.center.x = circle.center.x + translation.x;
    circleOut.center.y = circle.center.y + translation.y;
    circleOut.radius = circle.radius;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      circleOut.center.x += center.x - circleOut.radius / 2;
      circleOut.center.y += center.y - circleOut.radius / 2;
    }
  } else {
    std::cout << "GAMEINFO: (geometry) translate not implemented!!!\n";
  }
}

void Geometry::render() const {
  if (std::holds_alternative<Rectangle>(_raw)) {
    const Rectangle &rec = std::get<Rectangle>(_raw);
    DrawRectangleLinesEx(rec, 1.0, GREEN);
  } else if (std::holds_alternative<Circle>(_raw)) {
    const Circle &circle = std::get<Circle>(_raw);
    DrawCircleLinesV(circle.center, circle.radius, GREEN);
  } else {
    std::cout << "GAMEINFO: (geometry) draw not implemented!!!\n";
  }
}
} // namespace game
