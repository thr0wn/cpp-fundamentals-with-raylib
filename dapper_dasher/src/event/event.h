#pragma once
#include <any>
#include <list>
#include <string>

namespace game {
class Event {
public:
  std::string name;
  std::any value;
  Event(std::string name, std::any value) : name(name), value(value) {}
};
} // namespace game
