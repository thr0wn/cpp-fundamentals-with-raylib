#include "ui/game-over.h"

namespace game {
GameOver::GameOver() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void GameOver::onInit() {
  _textGameOver.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  _textGameOver.setAlign(GAME_TEXT_ALIGN_CENTER);

  _textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH,
       _textGameOver.getPosition().y + _textGameOver.getHeight()});
  _textRestart.setAlign(GAME_TEXT_ALIGN_CENTER);

  _textQuit.setPosition(
      {0.5 * config::WINDOW_WIDTH,
       _textRestart.getPosition().y + _textRestart.getHeight()});
  _textQuit.setAlign(GAME_TEXT_ALIGN_CENTER);
  _log->info("(game-over-ui) Game Over UI initialized.");
}

void GameOver::onRender() {
  if (!_gameState->gameOver()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  GuiLabel(_textGameOver.getRectangle(), _textGameOver.getC_str());

  _textRestartIsPressed =
      GuiLabelButton(_textRestart.getRectangle(), _textRestart.getC_str());

  _textQuitIsPressed =
      GuiLabelButton(_textQuit.getRectangle(), _textQuit.getC_str());

  if (_textRestartIsPressed) {
    _gameState->restart();
  }
  if (_textQuitIsPressed) {
    _gameState->stop();
  }
}
} // namespace game
