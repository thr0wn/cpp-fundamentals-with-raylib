#pragma once
#include "config.hpp"
#include "game-node.hpp"
#include "game-service.hpp"
#include "raylib.h"

#define START_TEXT_NEW_GAME "New Game"
#define START_TEXT_QUIT "Quit"
#define START_TEXT_SIZE 48

class Start : public GameNode {
  const char *textNewGame = START_TEXT_NEW_GAME;
  const char *textQuit = START_TEXT_QUIT;

public:
  void renderOut() override;
};
