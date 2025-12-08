#include "game/game.h"

namespace game {
int start() {
  logService = new LogService();
  gameService = new GameService();
  databaseService = new DatabaseService();
  scheduleService = new ScheduleService();
  tileService = new TileService();
  UI *ui = new UI();
  Background *background = new Background();
  // Player *player = new Player();
  // Nebula *nebula = new Nebula();
  // Start *start = new Start();
  // Pause *pause = new Pause();
  // Score *score = new Score();
  // GameOver *gameOver = new GameOver();
  gameService->push(logService);
  gameService->push(databaseService);
  gameService->push(scheduleService);
  gameService->push(tileService);
  gameService->push(background);
  gameService->push(ui);  
  // gameService->push(player);
  // gameService->push(nebula);
  // gameService->push(start);
  // gameService->push(pause);
  // gameService->push(score);
  // gameService->push(gameOver);

  gameService->_start();
  while (!gameService->shouldClose()) {
    gameService->_update();
    gameService->_render();
    gameService->_renderOut();
  }
  gameService->_stop();

  delete logService;
  delete gameService;
  delete databaseService;
  delete scheduleService;
  delete tileService;
  delete background;
  delete ui;  

  return 0;
}

void stop() {
  if (gameService != NULL) {
    gameService->stopGame();
  }
}

} // namespace game
