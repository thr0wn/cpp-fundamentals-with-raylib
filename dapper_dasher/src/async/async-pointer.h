#pragma once

#include <any>
#include <list>
#include <algorithm>
#include <memory>

namespace game {
namespace AsyncPointer {

extern std::list<std::any> pointers;

void push(const std::any &pointer);
template <typename T> T *get() {
  auto pointerIt = std::find_if(pointers.begin(), pointers.end(),
                                [](const std::any &ptr) {
                                return ptr.type() == typeid(T*);
                                });
  if (pointerIt != pointers.end()) {
    return std::any_cast<T*>(*pointerIt);
  }
  return nullptr;
}
} // namespace AsyncPointer
} // namespace game
