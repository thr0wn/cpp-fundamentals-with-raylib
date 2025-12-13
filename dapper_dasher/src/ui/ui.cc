#include "ui/ui.h"

namespace game {
UI::UI() : GameNode("ui") {};

void UI::start() {
  push(&startUI);
  push(&pauseUI);  
  push(&scoreUI);
  push(&gameOverUI);  
}

void UI::stop() {
  erase(&startUI);
  erase(&pauseUI);  
  erase(&scoreUI);  
  erase(&gameOverUI);
}
} // namespace game
