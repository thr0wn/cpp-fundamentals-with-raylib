#include "ui/start.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace game {
Start::Start() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
};

void Start::onInit() {
  textNewGame.setSize(config::TEXT_SIZE_LARGE);
  textNewGame.setPosition(
      {0.025f * config::WINDOW_WIDTH, 0.7f * config::WINDOW_HEIGHT});

  textQuit.setSize(config::TEXT_SIZE_LARGE);
  textQuit.setPosition({0.025f * config::WINDOW_WIDTH,
                        textNewGame.getPosition().y + textNewGame.getHeight()});
  logService->info("(start-ui) Start UI initialized.");  
}

void Start::onRender() {
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
    gameService->start();
  }
  if (textQuitIsPressed) {
    gameService->stop();
  }
}
} // namespace game
