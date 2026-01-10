#include "event/event.h"

namespace game {
Event::Event(const std::string &name, const std::any &value)
    : _name(name), _value(value) {}

std::string &Event::name() { return _name; }
const std::string &Event::name() const { return _name; }

std::any &Event::value() { return _value; }
const std::any &Event::value() const { return _value; }

} // namespace game
