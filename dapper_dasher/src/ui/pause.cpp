#include "ui/pause.hpp"

void Pause::start() {
  textResumeRec.x = 0.5f * config::WINDOW_WIDTH;
  textResumeRec.y = 0.4f * config::WINDOW_HEIGHT;
  textResumeRec.width = config::TEXT_UNIT_WITDH * config::TEXT_LARGE_SIZE * textResume.length();
  textResumeRec.height = config::TEXT_UNIT_HEIGHT * config::TEXT_LARGE_SIZE;
  textResumeRec.x -= textResumeRec.width/2;  

  textRestartRec.x = 0.5f * config::WINDOW_WIDTH;
  textRestartRec.y = textResumeRec.y + config::TEXT_UNIT_HEIGHT * config::TEXT_LARGE_SIZE;
  textRestartRec.width = config::TEXT_UNIT_WITDH * config::TEXT_LARGE_SIZE * textResume.length();
  textRestartRec.height = config::TEXT_UNIT_HEIGHT * config::TEXT_LARGE_SIZE;
  textRestartRec.x -= textRestartRec.width/2;
  
  textQuitRec.x = 0.5f * config::WINDOW_WIDTH;
  textQuitRec.y = textRestartRec.y + config::TEXT_UNIT_HEIGHT * config::TEXT_LARGE_SIZE;
  textQuitRec.width = config::TEXT_UNIT_WITDH * config::TEXT_LARGE_SIZE * textQuit.length();
  textQuitRec.height = config::TEXT_UNIT_HEIGHT * config::TEXT_LARGE_SIZE;
  textQuitRec.x -= textQuitRec.width/2;
}

void Pause::update() { 
  if (gameService::isRunning() && (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
    gameService::pauseGame();
  }
}

void Pause::render() { 
  if (!gameService::isPaused()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_LARGE_SIZE);
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
