#pragma once
#include <any>
#include <list>
#include <string>

namespace game {
class Event {
private:
  std::string _name;
  std::any _value;

public:
  Event(const std::string &name, const std::any &value);

  const std::string &getName() const;

  const std::any &getValue() const;
};
} // namespace game
