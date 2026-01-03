#include "tile/texture-loader.h"

namespace game {
TextureLoader::TextureLoader() {
  emitter->on("game/init", [this](Event event) { onInit(); });
  emitter->on("game/deinit", [this](Event event) { onDeinit(); });
};

void TextureLoader::onInit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(textureUrls[i]);
  }
  loaded = true;
  log->info("(texture-loader) Loaded textures.");
}

void TextureLoader::onDeinit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
  log->info("(texture-loader) Unloaded textures.");
}

} // namespace game
