#include "ui/pause.h"

namespace game {
Pause::Pause() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Pause::onInit() {
  _textResume.position() = 
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT};
  _textResume.align() = GAME_TEXT_ALIGN_CENTER;

  _textRestart.position() = 
      {0.5f * config::WINDOW_WIDTH,
       _textResume.position().y + _textResume.height()};
  _textRestart.align() = GAME_TEXT_ALIGN_CENTER;

  _textQuit.position() = {0.5 * config::WINDOW_WIDTH,
                          _textRestart.position().y + _textRestart.height()};
  _textQuit.align() = GAME_TEXT_ALIGN_CENTER;
  _log->info("(pause-ui) Pause UI initialized.");
}

void Pause::onUpdate() {
  if (_gameState->running() &&
      (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
    _gameState->pause();
  }
}

void Pause::onRender() {
  if (!_gameState->paused()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  _textResumeIsPressed =
      GuiLabelButton(_textResume.rectangle(), _textResume.c_str());
  _textRestartIsPressed =
      GuiLabelButton(_textRestart.rectangle(), _textRestart.c_str());
  _textQuitIsPressed =
      GuiLabelButton(_textQuit.rectangle(), _textQuit.c_str());

  if (_textResumeIsPressed) {
    _gameState->resume();
  }
  if (_textRestartIsPressed) {
    _gameState->restart();
  }
  if (_textQuitIsPressed) {
    _gameState->stop();
  }
}
} // namespace game
