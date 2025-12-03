#include "start.hpp"

void Start::start() {
  textNewGameRec.x = (0.25f / 10.f) * windowWidth;
  textNewGameRec.y = ((6.5f / 10.f) * windowHeight);
  textNewGameRec.width = .5f * START_TEXT_SIZE * textNewGame.length();   
  textNewGameRec.height = 1.2f * START_TEXT_SIZE;   

  textQuitGameRec.x = (0.25f / 10.f) * windowWidth;
  textQuitGameRec.y = (8.0f / 10.f) * windowHeight;
  textNewGameRec.width = .5f * START_TEXT_SIZE * textQuit.length();   
  textNewGameRec.height = 1.2f * START_TEXT_SIZE;     
}

void Start::render() {
  if (!GameService::isStartUI()) {
    return;
  }
  //GuiButton(textNewGameRec, textNewGame.data());
  //  DrawText(textNewGame.data(), textNewGameRec.x, textNewGameRec.y, START_TEXT_SIZE, WHITE);
  // DrawText(textQuit.data(), textQuitGameRec.x, textQuitGameRec.y, START_TEXT_SIZE, WHITE);
}
