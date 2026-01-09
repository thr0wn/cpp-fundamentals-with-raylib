#include "ui/game-over.h"

namespace game {
GameOver::GameOver() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void GameOver::onInit() {
  _textGameOver.position() = 
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT};
  _textGameOver.align() = GAME_TEXT_ALIGN_CENTER;
  
  _textRestart.position() = 
      {0.5f * config::WINDOW_WIDTH,
       _textGameOver.position().y + _textGameOver.height()};
  _textRestart.align() = GAME_TEXT_ALIGN_CENTER;
  
  _textQuit.position() = {0.5 * config::WINDOW_WIDTH,
                        _textRestart.position().y + _textRestart.height()};
  _textQuit.align() = GAME_TEXT_ALIGN_CENTER;
  _log->info("(game-over-ui) Game Over UI initialized.");
}

void GameOver::onRender() {
  if (!_gameState->gameOver()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  GuiLabel(_textGameOver.rectangle(), _textGameOver.c_str());

  _textRestartIsPressed =
      GuiLabelButton(_textRestart.rectangle(), _textRestart.c_str());

  _textQuitIsPressed =
      GuiLabelButton(_textQuit.rectangle(), _textQuit.c_str());

  if (_textRestartIsPressed) {
    _gameState->restart();
  }
  if (_textQuitIsPressed) {
    _gameState->stop();
  }
}
} // namespace game
