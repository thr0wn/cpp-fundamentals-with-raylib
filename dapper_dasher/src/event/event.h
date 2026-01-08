#pragma once
#include <any>
#include <list>
#include <string>

namespace game {
class Event {
public:
  std::string name;
  std::any value;
  Event(std::string name, std::any value);
};
} // namespace game
