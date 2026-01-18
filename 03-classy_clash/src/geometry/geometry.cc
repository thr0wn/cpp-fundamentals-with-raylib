#include "geometry/geometry.h"

namespace game {
RawGeometry &Geometry::raw() { return _raw; }
const RawGeometry &Geometry::raw() const { return _raw; }

GeometryPivot &Geometry::pivot() { return _pivot; }
const GeometryPivot &Geometry::pivot() const { return _pivot; }

Vector2 &Geometry::position() { return _position; }
const Vector2 &Geometry::position() const { return _position; }

Vector2 &Geometry::origin() { return _origin; }
const Vector2 &Geometry::origin() const { return _origin; }

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

void Geometry::update() const {
  if (std::holds_alternative<Rectangle>(_raw)) {
    Rectangle rec = std::get<Rectangle>(_raw);
    rec.x = _origin.x + _position.x;
    rec.y = _origin.y + _position.y;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      rec.x -= rec.width / 2;
      rec.y -= rec.height / 2;
    }
  } else if (std::holds_alternative<Circle>(_raw)) {
    Circle circle = std::get<Circle>(_raw);
    circle.center.x = _origin.x + _position.x;
    circle.center.y = _origin.y + _position.y;
    circle.radius = circle.radius;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      circle.center.x -= circle.radius / 2;
      circle.center.y -= circle.radius / 2;
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
