#pragma once
#include "event/event.h"
#include <functional>
#include <string>

namespace game {
typedef std::function<void(const Event&)> ListenerFunction;
class Listener {
public:
  std::string name;
  ListenerFunction function;
  Listener(std::string name, ListenerFunction function);
};
} // namespace game
