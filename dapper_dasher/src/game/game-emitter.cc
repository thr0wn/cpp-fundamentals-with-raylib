#include "game/game-emitter.h"

namespace game {
GameEmitter::GameEmitter() : Emitter("game-emitter") {}

void GameEmitter::start() {
  Event beforeStartEvent{"game/start:before", {}};
  Event startEvent{"game/start", {}};
  Event afterStartEvent{"game/start:after", {}};

  emit(beforeStartEvent);
  emit(startEvent);
  emit(afterStartEvent);
}
void GameEmitter::update() {
  Event beforeUpdateEvent{"game/update:before", {}};
  Event updateEvent{"game/update", {}};
  Event afterUpdateEvent{"game/update:after", {}};

  emit(beforeUpdateEvent, {{"log", false}});
  emit(updateEvent, {{"log", false}});
  emit(afterUpdateEvent, {{"log", false}});
}
void GameEmitter::render() {
  Event beforeRenderEvent{"game/render:before", {}};
  Event renderEvent{"game/render", {}};
  Event afterRenderEvent{"game/render:after", {}};

  emit(beforeRenderEvent, {{"log", false}});
  emit(renderEvent, {{"log", false}});
  emit(afterRenderEvent, {{"log", false}});
}
void GameEmitter::stop() {
  Event beforeStopEvent{"game/stop:before", {}};
  Event stopEvent{"game/stop", {}};
  Event afterStopEvent{"game/stop:after", {}};

  emit(beforeStopEvent);
  emit(stopEvent);
  emit(afterStopEvent);
}
GameEmitter gameEmitter;
} // namespace game
