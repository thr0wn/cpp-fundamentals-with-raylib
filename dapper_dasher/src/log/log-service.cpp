#include "log/log-service.hpp"

namespace logService {
void log(std::string message) {
  puts("-----------------------------------");
  printf("GAMELOG: %s", message.data());
  puts("\n-----------------------------------");    
  fflush(stdout);
}
} // namespace logService
