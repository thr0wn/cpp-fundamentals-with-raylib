#include "ui/pause.hpp"
#include "game/game-service.hpp"
#include "raylib.h"

void Pause::start() {
  textResumeRec.x = 0.5f * config::WINDOW_WIDTH;
  textResumeRec.y = 0.4f * config::WINDOW_HEIGHT;
  textResumeRec.width = config::TEXT_UNIT_WITDH * textResume.length();
  textResumeRec.height = config::TEXT_UNIT_HEIGHT;
  textResumeRec.x -= textResumeRec.width/2;  

  textRestartRec.x = 0.5f * config::WINDOW_WIDTH;
  textRestartRec.y = 0.4 * config::WINDOW_HEIGHT + 1.25f * config::TEXT_SIZE;
  textRestartRec.width = config::TEXT_UNIT_WITDH * textResume.length();
  textRestartRec.height = config::TEXT_UNIT_HEIGHT;
  textRestartRec.x -= textRestartRec.width/2;
  
  textQuitRec.x = 0.5f * config::WINDOW_WIDTH;
  textQuitRec.y = 0.4 * config::WINDOW_HEIGHT + 2.5f * config::TEXT_SIZE;
  textQuitRec.width = config::TEXT_UNIT_WITDH * textQuit.length();
  textQuitRec.height = config::TEXT_UNIT_HEIGHT;
  textQuitRec.x -= 0.75f * textQuitRec.width/2;
}

void Pause::update() {
if (!gameService::isStarted()) {
    return;
  }  
  if ((IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
    gameService::pauseGame();
    gameService::log("Pause");    
  }    
  if (!gameService::isPaused()) {
    return;
  }
}

void Pause::render() { 
  if (!gameService::isPaused()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  textResumeIsPressed = GuiLabelButton(textResumeRec, textResume.data());
  textRestartIsPressed = GuiLabelButton(textRestartRec, textRestart.data());
  textQuitIsPressed = GuiLabelButton(textQuitRec, textQuit.data());

  if (textResumeIsPressed) {
    gameService::resumeGame();
  }
  if (textRestartIsPressed) {
    gameService::restartGame();
  }
  if (textQuitIsPressed) {
    gameService::stopGame();
  }
}
