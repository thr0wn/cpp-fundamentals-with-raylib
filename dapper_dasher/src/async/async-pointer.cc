#include "async/async-pointer.h"

namespace game {
namespace AsyncPointer {

std::list<std::any> pointers;
 // namespace
void push(const std::any &pointer) {
  pointers.push_back(pointer);
}
} // namespace AsyncPointer
} // namespace game
