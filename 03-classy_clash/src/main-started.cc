#include "game/game.h"

int main() {
  game::init();
  game::start({{"autoStart", true}});
  game::deinit();
  return 0;
}
