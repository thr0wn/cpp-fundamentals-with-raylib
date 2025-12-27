#include "log/log-service.h"

namespace game {
LogService::LogService() {}

void LogService::info(std::string message) {
  if (enabled)
    std::cout << fmt::format("GAMEINFO: {}\n", message.data());
}

void LogService::setEnabled(bool enabled) { this->enabled = enabled; }
bool LogService::isEnabled() { return enabled; }

std::unique_ptr<LogService> logService;
} // namespace game
