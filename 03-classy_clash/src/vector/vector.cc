#include "vector/vector.h"

namespace game {
namespace Vector {
void copy(Vector2 &source, Vector2 &target) {
  source.x = target.x;
  source.y = target.y;
}
void copy(Vector3 &source, Vector3 &target) {
  source.x = target.x;
  source.y = target.y;
  source.z = target.z;
}
} // namespace Vector
} // namespace game
