#include "geometry/geometry.h"

namespace game {
Geometry::Geometry(){};
Geometry::Geometry(RawGeometry raw) : _raw(raw){};

void Geometry::setRaw(const RawGeometry &raw) { _raw = raw; }
const RawGeometry &Geometry::getRaw() const { return _raw; }

void Geometry::setOriginType(GeometryOrigin originType) { _originType = originType; }
GeometryOrigin Geometry::getOriginType() const { return _originType; }

bool Geometry::collides(Geometry *other) const {
  if (std::holds_alternative<Rectangle *>(_raw) &&
      std::holds_alternative<Rectangle *>(other->_raw)) {
    Rectangle *rectangle = std::get<Rectangle *>(_raw);
    Rectangle *rectangleOther = std::get<Rectangle *>(other->_raw);
    return CheckCollisionRecs(*rectangle, *rectangleOther);
  } else if (std::holds_alternative<Rectangle *>(_raw) &&
             std::holds_alternative<Circle *>(other->_raw)) {
    Rectangle *rectangle = std::get<Rectangle *>(_raw);
    Circle *circle = std::get<Circle *>(other->_raw);
    return CheckCollisionCircleRec(circle->center, circle->radius, *rectangle);
  } else if (std::holds_alternative<Circle *>(_raw) &&
             std::holds_alternative<Rectangle *>(other->_raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    Rectangle *rectangle = std::get<Rectangle *>(other->_raw);
    return CheckCollisionCircleRec(circle->center, circle->radius, *rectangle);
  } else if (std::holds_alternative<Circle *>(_raw) &&
             std::holds_alternative<Circle *>(other->_raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    Circle *circleOther = std::get<Circle *>(other->_raw);
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
    rec->x = _origin.x + _worldPosition.x;
    rec->y = _origin.y + _worldPosition.y;
    if (_originType == GEOMETRY_ORIGIN_CENTER) {
      rec->x -= rec->width / 2;
      rec->y -= rec->height / 2;
    }
  } else if (std::holds_alternative<Circle *>(_raw)) {
    Circle *circle = std::get<Circle *>(_raw);
    circle->center.x = _origin.x + _worldPosition.x;
    circle->center.y = _origin.y + _worldPosition.y;
    circle->radius = circle->radius;
    if (_originType == GEOMETRY_ORIGIN_CENTER) {
      circle->center.x -= circle->radius / 2;
      circle->center.y -= circle->radius / 2;
    }
  } else {
    std::cout << "GAMEINFO: (geometry) translate not implemented!!!\n";
  }
}

void Geometry::render() {
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
