#include "geometry/geometry.h"

namespace game {
Geometry::Geometry() {};
Geometry::Geometry(RawGeometry raw): _raw(raw) {};

RawGeometry &Geometry::raw() { return _raw; }
const RawGeometry &Geometry::raw() const { return _raw; }

GeometryPivot &Geometry::pivot() { return _pivot; }
const GeometryPivot &Geometry::pivot() const { return _pivot; }

bool Geometry::collides(const Geometry &other) const {
  if (std::holds_alternative<Rectangle *>(_raw) &&
      std::holds_alternative<Rectangle *>(other._raw)) {
    Rectangle *rectangle = std::get<Rectangle *>(_raw);
    Rectangle *rectangleOther = std::get<Rectangle *>(other._raw);
    return CheckCollisionRecs(*rectangle, *rectangleOther);
  } else if (std::holds_alternative<Rectangle *>(_raw) &&
             std::holds_alternative<Circle *>(other._raw)) {
    Rectangle *rectangle = std::get<Rectangle *>(_raw);
    Circle *circle = std::get<Circle *>(other._raw);
    return CheckCollisionCircleRec(circle->center, circle->radius, *rectangle);
  } else if (std::holds_alternative<Circle *>(_raw) &&
             std::holds_alternative<Rectangle *>(other._raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    Rectangle *rectangle = std::get<Rectangle *>(other._raw);
    return CheckCollisionCircleRec(circle->center, circle->radius, *rectangle);
  } else if (std::holds_alternative<Circle *>(_raw) &&
             std::holds_alternative<Circle *>(other._raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    Circle *circleOther = std::get<Circle *>(other._raw);
    return CheckCollisionCircles(circle->center, circle->radius,
                                 circleOther->center, circle->radius);
  }
  std::cout << "GAMEINFO: (geometry) checkCollision not implemented!!!\n";
  return false;
}

void Geometry::update() {
  Node2D::update();  
  if (std::holds_alternative<Rectangle *>(_raw)) {
    Rectangle *rec = std::get<Rectangle *>(_raw);
    rec->x = _origin.x + _position.x;
    rec->y = _origin.y + _position.y;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      rec->x -= rec->width / 2;
      rec->y -= rec->height / 2;
    }
  } else if (std::holds_alternative<Circle *>(_raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    circle->center.x = _origin.x + _position.x;
    circle->center.y = _origin.y + _position.y;
    circle->radius = circle->radius;
    if (_pivot == GEOMETRY_PIVOT_CENTER) {
      circle->center.x -= circle->radius / 2;
      circle->center.y -= circle->radius / 2;
    }
  } else {
    std::cout << "GAMEINFO: (geometry) translate not implemented!!!\n";
  }
}

void Geometry::render() const {
  Node2D::render();  
  if (std::holds_alternative<Rectangle *>(_raw)) {
    Rectangle *rec = std::get<Rectangle *>(_raw);
    DrawRectangleLinesEx(*rec, 1.0, GREEN);
  } else if (std::holds_alternative<Circle *>(_raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    DrawCircleLinesV(circle->center, circle->radius, GREEN);
  } else {
    std::cout << "GAMEINFO: (geometry) draw not implemented!!!\n";
  }
}
} // namespace game
