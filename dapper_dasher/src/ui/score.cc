#include "ui/score.h"

namespace game {
using config::TEXT_SIZE_SMALL;

Score::Score() {
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });

  // Get score reference
  gameEmitter->on("player/score", [this](Event event) {
    score = std::any_cast<int *>(event.value);
  });
  // Get highScore reference  
  gameEmitter->on("player/highScore", [this](Event event) {
    highScore = std::any_cast<int *>(event.value);
  });  
};

void Score::onStart() {
  // ui
  textScore.setSize(config::TEXT_SIZE_MEDIUM);
  textScore.setPosition(
      {0.025f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT});

  textHighScore.setSize(config::TEXT_SIZE_MEDIUM);
  textHighScore.setPosition(
      {0.025f * config::WINDOW_WIDTH,
       textScore.getPosition().y + textScore.getHeight()});

  textPressSpace.setSize(config::TEXT_SIZE_SMALL);
  textPressSpace.setPosition(
      {0.975f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT});
  textPressSpace.alignRight();
  gameEmitter->emit({"log/info", std::string("(score-ui) Score UI started.")});
}

void Score::onRender() {
  if (!gameService->isRunning()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  if (score != nullptr) {
    std::string formattedScore =
        fmt::format("{}: {}", textScore.getChars(), *score);
    GuiLabelButton(textScore.getRectangle(), formattedScore.data());
  }

  if (highScore != nullptr) {
    std::string formattedHighScore = fmt::format(
        "{}: {}", textHighScore.getString(), *highScore);
    GuiLabelButton(textHighScore.getRectangle(), formattedHighScore.data());
  }

  GuiSetStyle(DEFAULT, TEXT_SIZE, TEXT_SIZE_SMALL);
  GuiLabelButton(textPressSpace.getRectangle(), textPressSpace.getChars());
}
} // namespace game
