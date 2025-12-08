#include "ui/start.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace game {
Start::Start() : GameNode("start"){};
  
void Start::start() {
  textNewGame.setSize(config::TEXT_SIZE_LARGE);
  textNewGame.setPosition(
      {0.025f * config::WINDOW_WIDTH, 0.7f * config::WINDOW_HEIGHT});

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.025f * config::WINDOW_WIDTH,
                        textNewGame.getPosition().y + textNewGame.getHeight()});
}

void Start::render() {
  if (gameService->isStarted()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  textNewGameIsPressed =
      GuiLabelButton(textNewGame.getRectangle(), textNewGame.getChars());
  textQuitIsPressed =
      GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

  if (!gameService->isStarted() && textNewGameIsPressed) {
    gameService->startGame();
  }
  if (textQuitIsPressed) {
    gameService->stopGame();
  }
}
} // namespace game
