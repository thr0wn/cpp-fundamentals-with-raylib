#include "ui/game-over.h"

namespace game {
GameOver::GameOver() {
  emitter->on("game/init", [this](Event event) { onInit(); });
  emitter->on("game/render", [this](Event event) { onRender(); });
};

void GameOver::onInit() {
  textGameOver.setSize(config::TEXT_SIZE_LARGE);
  textGameOver.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  textGameOver.alignCenter();

  textRestart.setSize(config::TEXT_SIZE_LARGE);
  textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH,
       textGameOver.getPosition().y + textGameOver.getHeight()});
  textRestart.alignCenter();

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.5 * config::WINDOW_WIDTH,
                        textRestart.getPosition().y + textRestart.getHeight()});
  textQuit.alignCenter();
  log->info("(game-over-ui) Game Over UI initialized.");
}

void GameOver::onRender() {
  if (!gameState->isGameOver()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  GuiLabel(textGameOver.getRectangle(), textGameOver.getChars());

  textRestartIsPressed =
      GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());

  textQuitIsPressed =
      GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

  if (textRestartIsPressed) {
    gameState->restart();
  }
  if (textQuitIsPressed) {
    gameState->stop();
  }
}
} // namespace game
