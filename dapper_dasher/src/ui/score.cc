#include "ui/score.h"

namespace game {

Score::Score() {
  _emitter->on("game/start", [this](Event event) { onStart(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Score::onStart() {
  // ui
  _textScore.position() = 
      {0.025f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT};

  _textHighScore.position() = 
      {0.025f * config::WINDOW_WIDTH,
       _textScore.position().y + _textScore.height()};

  _textPressSpace.position() = 
      {0.975f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT};
  _textPressSpace.align() = GAME_TEXT_ALIGN_RIGHT;
  _log->info("(score-ui) Score UI started.");
}

void Score::onRender() {
  if (!_gameState->running()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  std::string formattedScore =
    fmt::format("{}: {}", _textScore.c_str(), _playerScore->score());
  GuiLabelButton(_textScore.rectangle(), formattedScore.c_str());

  std::string formattedHighScore =
      fmt::format("{}: {}", _textHighScore.string(), _playerScore->highScore());
  GuiLabelButton(_textHighScore.rectangle(), formattedHighScore.c_str());

  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_SMALL);
  GuiLabelButton(_textPressSpace.rectangle(), _textPressSpace.c_str());
}
} // namespace game
