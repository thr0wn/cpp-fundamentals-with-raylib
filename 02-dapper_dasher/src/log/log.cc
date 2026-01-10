#include "log/log.h"

namespace game {
void Log::info(const std::string &message) {
  if (_enabled)
    std::cout << fmt::format("GAMEINFO: {}\n", message);
}

bool &Log::enabled() { return _enabled; }
const bool &Log::enabled() const { return _enabled; }
} // namespace game
