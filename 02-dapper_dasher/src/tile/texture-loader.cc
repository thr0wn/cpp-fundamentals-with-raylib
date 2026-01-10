#include "tile/texture-loader.h"

namespace game {
TextureLoader::TextureLoader() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/deinit", [this](Event event) { onDeinit(); });
};

void TextureLoader::onInit() {
  for (int i = 0; i < config::NUMBER_OF_TEXTURES; i++) {
    _textures[i] = LoadTexture(_textureUrls[i]);
  }
  _log->info("(texture-loader) Loaded textures.");
}

void TextureLoader::onDeinit() {
  for (int i = 0; i < config::NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(_textures[i]);
  }
  _log->info("(texture-loader) Unloaded textures.");
}

const char * const *TextureLoader::textureUrls() const { return _textureUrls; };
const Texture2D *TextureLoader::textures() const { return _textures; };

} // namespace game
