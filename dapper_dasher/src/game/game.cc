#include "game/game.h"

namespace game {
int start() {
  UI ui;
  Background background;
  Player player;
  Nebula nebula;
  gameService.push(&logService);
  gameService.push(&scheduleService);
  gameService.push(&tileService);
  gameService.push(&background);
  gameService.push(&databaseService); // must be after others
  gameService.push(&player);
  gameService.push(&nebula);
  gameService.push(&ui);

  gameService._start();
  while (!gameService.shouldClose()) {
    gameService._update();
    gameService._render();
    gameService._renderOut();
  }
  gameService._stop();

  return 0;
}

void stop() { gameService.stopGame(); }

} // namespace game
