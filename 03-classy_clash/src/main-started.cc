#include "game/game.h"

int main() {
  game::init();
  game::start({true});
  game::deinit();
  return 0;
}
