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
#include "node/node-manager.h"
#include <memory>
#include <variant>
#include <string>

namespace game {
typedef std::variant<bool, int, float, std::string> Option;
typedef std::map<std::string, Option> StartOptions;
inline StartOptions defaultStartOptions{{"autoStart", false}};

void init();
void start(StartOptions options = defaultStartOptions);
void stop();
void deinit();
} // namespace game
