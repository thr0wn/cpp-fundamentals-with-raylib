#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include <string>

class Start : public GameNode {
  const std::string textNewGame = config::START_TEXT_NEW_GAME;
  Rectangle textNewGameRec;
  bool textNewGameIsPressed = false;  
  
  const std::string textQuit = config::START_TEXT_QUIT;
  Rectangle textQuitRec;
  bool textQuitIsPressed = false;    

public:
  void start() override;
  void render() override;
};
