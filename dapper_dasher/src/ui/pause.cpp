#include "ui/pause.hpp"

namespace game {
void Pause::start() {
  setName("pause-ui");  
  textResume.setSize(config::TEXT_SIZE_LARGE);
  textResume.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  textResume.alignCenter();

  textRestart.setSize(config::TEXT_SIZE_LARGE);
  textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH,
       textResume.getPosition().y + textResume.getHeight()});
  textRestart.alignCenter();

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.5 * config::WINDOW_WIDTH,
                        textRestart.getPosition().y + textRestart.getHeight()});
  textQuit.alignCenter();
}

void Pause::update() {
  if (gameService.isRunning() &&
      (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
    gameService.pauseGame();
  }
}

void Pause::render() {
  if (!gameService.isPaused()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  textResumeIsPressed =
      GuiLabelButton(textResume.getRectangle(), textResume.getChars());
  textRestartIsPressed =
      GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());
  textQuitIsPressed =
      GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

  if (textResumeIsPressed) {
    gameService.resumeGame();
  }
  if (textRestartIsPressed) {
    gameService.restartGame();
  }
  if (textQuitIsPressed) {
    gameService.stopGame();
  }
}
} // namespace game
