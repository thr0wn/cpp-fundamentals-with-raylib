#include "ui/game-over.h"

namespace game {
GameOver::GameOver() : GameNode("game-over") {};

void GameOver::start() {
  textRestart.setSize(config::TEXT_SIZE_LARGE);
  textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  textRestart.alignCenter();

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.5 * config::WINDOW_WIDTH,
                        textRestart.getPosition().y + textRestart.getHeight()});
  textQuit.alignCenter();
}

void GameOver::render() {
  if (!gameService.isGameOver()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  textRestartIsPressed =
      GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());
  textQuitIsPressed =
      GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

  if (textRestartIsPressed) {
    gameService.restartGame();
  }
  if (textQuitIsPressed) {
    gameService.stopGame();
  }
}
} // namespace game
