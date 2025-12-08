#pragma once
#include "config/config.hpp"
#include "database/database-service.hpp"
#include "game/game-node.hpp"
#include "game/game-state.hpp"
#include "list"
#include "tile/tile-service.hpp"
#include "timer/schedule-service.hpp"

namespace game {
class GameService : public GameNode {
  GameState gameState;

public:
  GameService();
  
  void _update() override;
  void _render() override;
  void _stop() override;
  
  void start() override;

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
extern GameService *gameService;
}; // namespace game
