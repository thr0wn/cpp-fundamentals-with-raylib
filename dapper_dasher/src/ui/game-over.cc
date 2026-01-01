#include "ui/game-over.h"

namespace game {
GameOver::GameOver() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
  gameEmitter->on("game/state", [this](Event event) {
    gameState = std::any_cast<GameState *>(event.value);
  });
};

void GameOver::onInit() {
  textRestart.setSize(config::TEXT_SIZE_LARGE);
  textRestart.setPosition(
      {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
  textRestart.alignCenter();

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.5 * config::WINDOW_WIDTH,
                        textRestart.getPosition().y + textRestart.getHeight()});
  textQuit.alignCenter();
  gameEmitter->emit(
      {"log/info", std::string("(game-over-ui) Game Over UI initialized.")});
}

void GameOver::onRender() {
  if (!gameState->isGameOver()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  textRestartIsPressed =
      GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());
  textQuitIsPressed =
      GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

  if (textRestartIsPressed) {
    gameEmitter->emit({"game/restart", {}}, {{"before", true}, {"after", true}});
  }
  if (textQuitIsPressed) {
    gameEmitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
  }
}
} // namespace game
