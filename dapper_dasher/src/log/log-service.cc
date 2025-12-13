#include "log/log-service.h"

namespace game {
  LogService::LogService(): GameNode("log-service") {}

  void LogService::log(std::string message) {
    printf("GAMELOG: %s\n", message.data());
    fflush(stdout);
  }

  LogService logService;
} // namespace game
