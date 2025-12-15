#pragma once
#include "config/config.h"

#include "event/event.h"
#include "event/emitter.h"
#include "event/listener.h"

#include "background/background.h"
#include "log/log-service.h"
#include "tile/tile-service.h"
#include "timer/schedule-service.h"
#include "game/game-service.h"
#include "nebula/nebula.h"
#include "player/player.h"
#include "raylib.h"
#include "ui/ui.h"


namespace game {
int start();
void stop();
} // namespace game
