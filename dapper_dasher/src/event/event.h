#pragma once
#include <any>
#include <string>
#include <list>

namespace game {
class Event {
public:
  std::string name;
  std::list<std::any> values;
  Event(std::string name, std::list<std::any> values);  
};
} // namespace game
