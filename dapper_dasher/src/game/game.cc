#include "game/game.h"

namespace game {
int start() {
  UI ui;
  Background background;
  Player player;
  Nebula nebula;
  gameService.push(&logService);
  gameService.push(&scheduleService);
  gameService.push(&tileService);
  gameService.push(&background);
  gameService.push(&databaseService); // must be after others
  gameService.push(&player);
  gameService.push(&nebula);
  gameService.push(&ui);

  // game/start event  
  Event beforeStartEvent{"game/start:before", {}};
  Event startEvent{"game/start", {}};
  Event afterStartEvent{"game/start:after", {}};

  // game/update event    
  Event beforeUpdateEvent{"game/update:before", {}};
  Event updateEvent{"game/update", {}};
  Event afterUpdateEvent{"game/update:after", {}};

  // game/render event    
  Event beforeRenderEvent{"game/render:before", {}};
  Event renderEvent{"game/render", {}};
  Event afterRenderEvent{"game/render:after", {}};

  // game/stop event    
  Event beforeStopEvent{"game/stop:before", {}};
  Event stopEvent{"game/stop", {}};
  Event afterStopEvent{"game/stop:after", {}};

  // start 
  gameEmitter.emit(beforeStartEvent);
  gameEmitter.emit(startEvent);
  gameEmitter.emit(afterStartEvent);
  while (!gameService.shouldClose()) {
    // update    
    gameEmitter.emit(beforeUpdateEvent, {{"log", false}});
    gameEmitter.emit(updateEvent, {{"log", false}});
    gameEmitter.emit(afterUpdateEvent, {{"log", false}});

    // render    
    gameEmitter.emit(beforeRenderEvent, {{"log", false}});
    gameEmitter.emit(renderEvent, {{"log", false}});
    gameEmitter.emit(afterRenderEvent, {{"log", false}});
  }
  gameEmitter.emit(beforeStopEvent);
  gameEmitter.emit(stopEvent);
  gameEmitter.emit(afterStopEvent);

  return 0;
}

void stop() { gameService.stopGame(); }

} // namespace game
