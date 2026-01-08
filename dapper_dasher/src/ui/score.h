#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "player/player-score.h"
#include "raygui.h"
#include "ui/text.h"
#include <fmt/format.h>
#include <string>

namespace game {
class Score {
  Text textScore{config::SCORE_TEXT_SCORE};

  Text textHighScore{config::SCORE_TEXT_HIGH_SCORE};

  Text textPressSpace{config::SCORE_TEXT_PRESS_SPACE};

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  PlayerScore *playerScore = AsyncPointer::get<PlayerScore>();
  Log *log = AsyncPointer::get<Log>();

public:
  Score() {
    emitter->on("game/start", [this](Event event) { onStart(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  };

  void onStart() {
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
    log->info("(score-ui) Score UI started.");
  }

  void onRender() {
    if (!gameState->isRunning()) {
      return;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

    std::string formattedScore =
        fmt::format("{}: {}", textScore.getChars(), playerScore->getScore());
    GuiLabelButton(textScore.getRectangle(), formattedScore.data());

    std::string formattedHighScore = fmt::format(
        "{}: {}", textHighScore.getString(), playerScore->getHighScore());
    GuiLabelButton(textHighScore.getRectangle(), formattedHighScore.data());

    GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_SMALL);
    GuiLabelButton(textPressSpace.getRectangle(), textPressSpace.getChars());
  }
};
} // namespace game
