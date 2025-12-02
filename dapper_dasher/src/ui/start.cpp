#include "start.hpp"

void Start::renderOut() {
  if (!GameService::isStartUI()) {
    return;
  }
  DrawText(textNewGame, (int)((0.25f / 10.f) * windowWidth),
           (int)((6.5f / 10.f) * windowHeight), START_TEXT_SIZE, WHITE);
  DrawText(textQuit, (int)((0.25f / 10.f) * windowWidth),
           (int)((8.0f / 10.f) * windowHeight), START_TEXT_SIZE, WHITE);
}
