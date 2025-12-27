#include "ui/score.h"

namespace game {
Score::Score() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
  gameEmitter->on("game/deinit", [this](Event event) { onDeinit(); });
};

void Score::onInit() {
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

  // score
  score = 0;  
  scheduleService->repeat(
      [this] {
        score++;
      },
      scoreInterval);
  loadHighScoreScore();
  logService->info("(score-ui) Score UI initialized.");
}

void Score::loadHighScoreScore() {
  std::string highscoreAsString = "0";
  keyValueRepository->get(highScoreKey, &highscoreAsString);
  highScore = std::stoi(highscoreAsString);
  logService->info(fmt::format("(score-ui) Restored a highscore of {}.", highScore));  
}

void Score::onRestart() {
  onDeinit();
  onInit();
  logService->info("(score-ui) Score UI restarted.");
}

void Score::onUpdate() {
  if (!gameService->isRunning()) {
    return;
  }
  if (score > highScore) {
    highScore = score;
    keyValueRepository->set(highScoreKey, std::to_string(highScore));
    logService->info("(score-ui) Score UI new highscore.");
  }
}

void Score::onRender() {
  if (!gameService->isRunning()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  std::string formattedScore =
      fmt::format("{}: {}", textScore.getChars(), score);
  GuiLabelButton(textScore.getRectangle(), formattedScore.data());

  std::string formattedHighScore =
      fmt::format("{}: {}", textHighScore.getString(), highScore);
  GuiLabelButton(textHighScore.getRectangle(), formattedHighScore.data());

  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_SMALL);
  GuiLabelButton(textPressSpace.getRectangle(), textPressSpace.getChars());
}

void Score::onDeinit() {
  keyValueRepository->set(highScoreKey, std::to_string(highScore));
  logService->info(fmt::format("(score-ui) Persisted a highscore of {}.", highScore));    
  logService->info("(score-ui) Score UI deinitialized.");
}
} // namespace game
