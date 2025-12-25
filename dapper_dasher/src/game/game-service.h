#pragma once
#include "config/config.h"
#include "event/emitter.h"
#include "event/listener.h"
#include "game/game-emitter.h"
#include "game/game-node.h"
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
  
  void start();
  void update();
  void render();
  void stop();  
  void onBeforeStart();
  void onBeforeRender();
  void onAfterRender();
  void onAfterStop();  

  // Start game changing the game state
  void startGame();
  // Check if the game is started
  bool isStarted();
  // Pause a game changing the game state
  void pauseGame();
  // Check if game is paused
  bool isPaused();
  // Set game over changing the game state
  void gameOver();
  // Check if game is over
  bool isGameOver();
  // Stop the game changing the game state
  void stopGame();
  // Check if the game should close
  bool shouldClose();
  // Resume/Unpause the game changing the game state
  void resumeGame();
  // Restart the game from the pause menu chaing the game state
  void restartGame();
  // Is Game started and not paused
  bool isRunning();
  // Return the current game state
  GameState getGameState();
};
  extern std::unique_ptr<GameService> gameService;
}; // namespace game
