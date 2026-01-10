#include "event/listener.h"

namespace game {
Listener::Listener(const std::string &eventName,
                   const ListenerFunction &function)
    : _eventName(eventName), _function(function) {
  _id = _idCounter++;
}

const std::uint32_t &Listener::id() const { return _id; };

const std::string &Listener::eventName() const { return _eventName; }

const ListenerFunction &Listener::function() const { return _function; }

} // namespace game
