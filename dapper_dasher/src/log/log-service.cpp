#include "log/log-service.hpp"

namespace logService {
void log(std::string message) {
  printf("GAMELOG: %s\n", message.data());
  fflush(stdout);
}
} // namespace logService
