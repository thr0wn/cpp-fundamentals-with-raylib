#pragma once
#include "game/game-emitter.h"
#include "game/game-node.h"
#include "async/async-pointer.h"
#include "log/log.h"
#include "tile/tile.h"
#include <map>
#include <any>

namespace game {
class TextureLoader {
public:
  TextureLoader();

  bool loaded;

  Log *log = AsyncPointer::get<Log>();
  
  const char *textureUrls[NUMBER_OF_TEXTURES] = {
      "resources/textures/scarfy.png", "resources/textures/far-buildings.png",
      "resources/textures/back-buildings.png",
      "resources/textures/foreground.png",
      "resources/textures/12_nebula_spritesheet.png"};
  Texture2D textures[NUMBER_OF_TEXTURES];

  void onInit();
  void onDeinit();
};
} // namespace game
