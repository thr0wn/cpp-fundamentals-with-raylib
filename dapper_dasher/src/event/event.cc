#include "event/event.h"

namespace game {
Event::Event(std::string name, std::list<std::any> arguments)
    : name(name), arguments(arguments) {}
} // namespace game
