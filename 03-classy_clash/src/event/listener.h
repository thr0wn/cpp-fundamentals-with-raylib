#pragma once
#include "event/event.h"
#include <cstdint>
#include <functional>
#include <string>

namespace game {
using ListenerFunction = std::function<void(const Event &)>;
class Listener {
private:
  inline static std::uint32_t _idCounter = 0;
  std::uint32_t _id;
  std::string _eventName;
  ListenerFunction _function;

public:
  Listener(const std::string &eventName, const ListenerFunction &function);

  const std::uint32_t &id() const;

  const std::string &eventName() const;

  const ListenerFunction &function() const;
};
} // namespace game
