#include "game/game.hpp"

namespace game {
  int start() {
    logService = new LogService();
    gameService = new GameService();
    tileService = new TileService();
    Background *background = new Background();
    // Player *player = new Player();
    // Nebula *nebula = new Nebula();
    // Start *start = new Start();
    // Pause *pause = new Pause();
    // Score *score = new Score();
    // GameOver *gameOver = new GameOver();
    //gameService->addGameNode(logService);
    //gameService->addGameNode(&scheduleService);
    gameService->addGameNode(logService);
    gameService->addGameNode(tileService);
    gameService->addGameNode(background);
    // gameService->addGameNode(player);
    // gameService->addGameNode(nebula);
    // gameService->addGameNode(start);
    // gameService->addGameNode(pause);
    // gameService->addGameNode(score);
    // gameService->addGameNode(gameOver);

    gameService->_start();
    while (!gameService->shouldClose()) {
      gameService->_update();
      gameService->_render();
      gameService->_renderOut();
    }
    gameService->_stop();

    delete background;
    delete gameService;
    delete databaseService;
    delete tileService;
    delete scheduleService;

    return 0;
  }

  void stop() {
    if (gameService != NULL) {
      gameService->_stop();      
    }
  }

} // namespace game
