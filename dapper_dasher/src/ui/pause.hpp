#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include <string>
#include "raygui.h"

#define START_TEXT_RESUME "Resume"
#define START_TEXT_RESTART "Quit"

class Pause : public GameNode {
  const std::string textNewGame = START_TEXT_NEW_GAME;
  Rectangle textNewGameRec;
  bool textNewGameIsPressed = false;  
  
  const std::string textQuit = START_TEXT_QUIT;
  Rectangle textQuitRec;
  bool textQuitIsPressed = false;    

public:
  void start() override;
  void render() override;
};
