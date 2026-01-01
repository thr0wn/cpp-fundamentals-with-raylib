#pragma once
#include "config/config.h"

#include "event/emitter.h"
#include "event/event.h"
#include "event/listener.h"
#include "game/game-emitter.h"
#include "log/log.h"
#include "game/game-service.h"
#include "tile/texture-loader.h"
#include "timer/schedule-service.h"
#include "database/database.h"
#include "nebula/nebula.h"
#include "player/player.h"
#include "background/background.h"
#include "raylib.h"
#include "ui/ui.h"
#include <memory>

namespace game {
void init();
void start();
void update();
void stop();
void deinit();
} // namespace game
