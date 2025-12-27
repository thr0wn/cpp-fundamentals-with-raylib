#pragma once
#include "config/config.h"
#include "event/emitter.h"
#include "event/listener.h"
#include "game/game-emitter.h"
#include "game/game-state.h"
#include "tile/tile-service.h"
#include "timer/schedule-service.h"
#include <list>
#include <memory>

namespace game {
class GameService {
  GameState gameState;

public:
  GameService();
  
  void init();
  void update();
  void render();
  void deinit();  
  void onBeforeInit();
  void onBeforeRender();
  void onAfterRender();
  void onAfterDeinit();  

  // Start game changing the game state
  void start();
  // Check if the game is started
  bool isStarted();
  // Pause a game changing the game state
  void pause();
  // Check if game is paused
  bool isPaused();
  // Set game over changing the game state
  void gameOver();
  // Check if game is over
  bool isGameOver();
  // Stop the game changing the game state
  void stop();
  // Check if the game should close
  bool shouldClose();
  // Resume/Unpause the game changing the game state
  void resume();
  // Restart the game from the pause menu chaing the game state
  void restart();
  // Is Game started and not paused
  bool isRunning();
  // Return the current game state
  GameState getGameState();
};
  extern std::unique_ptr<GameService> gameService;
}; // namespace game
