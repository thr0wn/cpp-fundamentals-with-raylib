#include "event/event.h"

namespace game {
Event::Event(const std::string &name, const std::any &value)
    : _name(name), _value(value) {}

const std::string &Event::getName() const { return _name; }

const std::any &Event::getValue() const { return _value; }

} // namespace game
