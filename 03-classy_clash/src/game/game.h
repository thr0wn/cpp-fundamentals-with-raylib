#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "event/event.h"
#include "event/listener.h"
#include "game/game-state.h"
#include "log/log.h"
#include "player/player.h"
#include "raylib.h"
#include "texture/texture-loader.h"
#include "ui/ui.h"
#include "world/world.h"
#include <memory>

namespace game {
typedef struct {
  bool autoStartGame;
} StartOptions;
inline StartOptions defaultStartOptions{false};

void init();
void start(StartOptions options = defaultStartOptions);
void stop();
void deinit();
} // namespace game
