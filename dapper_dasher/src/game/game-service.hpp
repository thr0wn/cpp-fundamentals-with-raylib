#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-state.hpp"
#include "tile/tile-service.hpp"
#include "timer/schedule-service.hpp"
#include "list"

class GameService {
  static GameState gameState;  
  static std::list<GameNode*> gameNodes;

public:
  static void addGameNode(GameNode *gameNode);  
  static void removeGameNode(GameNode *gameNode);

  static void start();
  static void update();
  static void render();
  static void renderOut();
  static void stop();

  static void startGame();
  static void pauseGame();
  static void closeGame();

  static bool isStartUI();  
  static bool isPauseUI();

  static bool shouldClose();

  static GameState getGameState();  
};
