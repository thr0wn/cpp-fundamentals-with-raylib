#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "event/event.h"
#include "event/listener.h"
#include "game/game-state.h"
#include "log/log.h"
#include "texture/texture-loader.h"
#include "database/database.h"
#include "world/world.h"
#include "player/player.h"
#include "raylib.h"
#include "ui/ui.h"
#include <memory>

namespace game {
void init();
void start();
void stop();
void deinit();
} // namespace game
