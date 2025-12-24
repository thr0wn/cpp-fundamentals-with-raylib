#pragma once

#include "event/emitter.h"

namespace game {
class GameEmitter : public Emitter {
public:
  GameEmitter();
  void start();
  void update();
  void render();
  void stop();
};
extern GameEmitter gameEmitter;
} // namespace game
