#include "ui/ui.h"

namespace game {
UI::UI() : GameNode("ui") {};

void UI::start() {
  startUI = new Start();
  // pauseUI = new Pause();
  // scoreUI = new Score();
  // gameOverUI = new GameOver();

  push(startUI);
  // push(pauseUI);  
  // push(scoreUI);  
  // push(gameOverUI);
  
}

void UI::stop() {
  erase(startUI);
  // erase(pauseUI);  
  // erase(scoreUI);  
  // erase(gameOverUI);  
  //delete startUI;
  // delete pauseUI;
  // delete scoreUI;
  // delete gameOverUI;
}
} // namespace game
