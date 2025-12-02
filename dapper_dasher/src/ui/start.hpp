#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "game-service.hpp"
#include "raylib.h"
#include <string>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define START_TEXT_NEW_GAME "New Game"
#define START_TEXT_QUIT "Quit"
#define START_TEXT_SIZE 48

class Start : public GameNode {
  const std::string textNewGame = START_TEXT_NEW_GAME;
  Rectangle textNewGameRec;
  bool textNewGameIsPressed = false;  
  
  const std::string textQuit = START_TEXT_QUIT;
  Rectangle textQuitGameRec;
  bool textQuitIsPressed = false;    

public:
  void start() override;
  void render() override;
};
