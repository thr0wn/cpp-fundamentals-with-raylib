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

  std::string &name();
  const std::string &name() const;

  std::any &value();
  const std::any &value() const;
};
} // namespace game
