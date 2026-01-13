#pragma once

#include <algorithm>
#include <any>
#include <list>
#include <memory>
#include <iostream>

namespace game {
namespace AsyncPointer {

inline std::list<std::any> _pointers;

template <typename T> void push(T *pointer) { _pointers.push_back(pointer); }
template <typename T> T *get() {
  auto pointerIt =
      std::find_if(_pointers.begin(), _pointers.end(), [](const std::any &ptr) {
        return ptr.type() == typeid(T *);
      });
  if (pointerIt != _pointers.end()) {
    return std::any_cast<T *>(*pointerIt);
  } else {
    std::cout << "GAMEINFO: (async-pointer) Pointer not found!";    
  }
  return nullptr;
}
inline void clear() { _pointers.clear(); }
} // namespace AsyncPointer
} // namespace game
