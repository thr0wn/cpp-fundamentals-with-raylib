#pragma once

#include <algorithm>
#include <any>
#include <list>
#include <memory>

namespace game {
namespace AsyncPointer {
namespace {
inline std::list<std::any> pointers;
}
template <typename T> void push(T *pointer) { pointers.push_back(pointer); }
template <typename T> T *get() {
  auto pointerIt =
      std::find_if(pointers.begin(), pointers.end(), [](const std::any &ptr) {
        return ptr.type() == typeid(T *);
      });
  if (pointerIt != pointers.end()) {
    return std::any_cast<T *>(*pointerIt);
  }
  return nullptr;
}
} // namespace AsyncPointer
} // namespace game
