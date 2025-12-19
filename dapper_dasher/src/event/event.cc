#include "event/event.h"

namespace game {
Event::Event(std::string name, std::list<std::any> values)
    : name(name), values(values) {}
} // namespace game
