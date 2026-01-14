#include "geometry/vector.h"

namespace game {
namespace vector {
void copy(Vector2 &source, Vector2 &target) {
  target.x = source.x;
  target.y = source.y;
}
void copy(Vector3 &source, Vector3 &target) {
  target.x = source.x;
  target.y = source.y;
  target.z = source.z;
}
} // namespace Vector
} // namespace game
