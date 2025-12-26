#pragma once
#include "config/config.h"

#include "background/background.h"
#include "event/emitter.h"
#include "event/event.h"
#include "event/listener.h"
#include "game/game-emitter.h"
#include "game/game-service.h"
#include "log/log-service.h"
#include "nebula/nebula.h"
#include "player/player.h"
#include "raylib.h"
#include "tile/tile-service.h"
#include "timer/schedule-service.h"
#include "ui/ui.h"
#include <memory>

namespace game {
void init();
void start();
void update();
void stop();
void deinit();
} // namespace game
