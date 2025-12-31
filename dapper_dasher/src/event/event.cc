#include "event/event.h"

namespace game {
Event::Event(std::string name, std::any value) : name(name), value(value) {}
} // namespace game
