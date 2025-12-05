#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-state.hpp"
#include "tile/tile-service.hpp"
#include "timer/schedule-service.hpp"
#include "list"

namespace gameService {
   // Add a new game node
  void addGameNode(GameNode *gameNode);
  // Remove a game node  
  void removeGameNode(GameNode *gameNode);

  // Initialization. Only Game should call it.
  void restart();
  // Reinitialization of game nodes
  void start();
  // Update logic.
  void update();
  // Do render  
  void render();
  // Render out of drawing. Only game should call it.  
  void renderOut();
  // Deinitialization. Only game should call it.
  void stop();

  // Start game changing the game state
  void startGame();
  // Check if the game is started  
  bool isStarted();
  // Pause a game changing the game state
  void pauseGame();
  // Check if game is paused
  bool isPaused();
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

  void log(std::string data);
};
