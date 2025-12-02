#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "game-state.hpp"
#include "tile-service.hpp"
#include "schedule-service.hpp"
#include "game-node.hpp"
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
  static GameState getGameState();  
};
