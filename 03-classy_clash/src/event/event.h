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

  const std::string &name() const;

  const std::any &value() const;
};
} // namespace game
