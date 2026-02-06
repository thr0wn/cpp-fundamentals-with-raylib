#include "ui/pause.h"

namespace game {
Pause::Pause() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Pause::onInit() {
  _textResume.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  _textResume.setAlign(GAME_TEXT_ALIGN_CENTER);

  _textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH,
       _textResume.getPosition().y + _textResume.getHeight()});
  _textRestart.setAlign(GAME_TEXT_ALIGN_CENTER);

  _textQuit.setPosition(
      {0.5 * config::WINDOW_WIDTH,
       _textRestart.getPosition().y + _textRestart.getHeight()});
  _textQuit.setAlign(GAME_TEXT_ALIGN_CENTER);
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
      GuiLabelButton(_textResume.getRectangle(), _textResume.getC_str());
  _textRestartIsPressed =
      GuiLabelButton(_textRestart.getRectangle(), _textRestart.getC_str());
  _textQuitIsPressed =
      GuiLabelButton(_textQuit.getRectangle(), _textQuit.getC_str());

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
