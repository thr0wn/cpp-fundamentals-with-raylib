#include "ui/start.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void Start::start() {
  textNewGameRec.x = 0.025f * config::WINDOW_WIDTH;
  textNewGameRec.y = 0.65f * config::WINDOW_HEIGHT;
  textNewGameRec.width = config::TEXT_UNIT_WITDH * textNewGame.length();   
  textNewGameRec.height = config::TEXT_UNIT_HEIGHT;   

  textQuitRec.x = (0.25f / 10.f) * config::WINDOW_WIDTH;
  textQuitRec.y = (8.0f / 10.f) * config::WINDOW_HEIGHT;
  textQuitRec.width = config::TEXT_UNIT_WITDH * textQuit.length();
  textQuitRec.height = config::TEXT_UNIT_HEIGHT;  
}

void Start::render() {
  if (gameService::isStarted()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE);  
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);  
  textNewGameIsPressed = GuiLabelButton(textNewGameRec, textNewGame.data());
  textQuitIsPressed = GuiLabelButton(textQuitRec, textQuit.data());

  if (!gameService::isStarted() && textNewGameIsPressed) {
    gameService::startGame();
  }
  if (textQuitIsPressed) {
    gameService::stopGame();
  }
}
