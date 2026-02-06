#include "ui/start.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace game {
Start::Start() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Start::onInit() {
  _textNewGame.setPosition(
      Vector2{0.025f * config::WINDOW_WIDTH, 0.6f * config::WINDOW_HEIGHT});

  _textQuit.setPosition(
      Vector2{0.025f * config::WINDOW_WIDTH,
              _textNewGame.getPosition().y + _textNewGame.getHeight()});
  _log->info("(start-ui) Initialized.");
}

void Start::onRender() {
  if (_gameState->started()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  _textNewGameIsPressed =
      GuiLabelButton(_textNewGame.getRectangle(), _textNewGame.getC_str());
  _textQuitIsPressed = GuiLabelButton(_textQuit.getRectangle(), _textQuit.getC_str());

  if (!_gameState->started() && _textNewGameIsPressed) {
    _gameState->start();
  }
  if (_textQuitIsPressed) {
    _gameState->stop();
  }
}
} // namespace game
