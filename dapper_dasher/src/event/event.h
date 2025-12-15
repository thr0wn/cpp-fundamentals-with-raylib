#pragma once
#include <any>
#include <string>
#include <list>

namespace game {
class Event {
public:
  std::string name;
  std::list<std::any> arguments;
  Event(std::string name, std::list<std::any> arguments);  
};
} // namespace game
