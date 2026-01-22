#include "texture/texture-loader.h"

namespace game {
TextureLoader::TextureLoader() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/deinit", [this](Event event) { onDeinit(); });

  memcpy(_textureUrls, config::TEXTURE_URLS, sizeof(config::TEXTURE_URLS));
};

void TextureLoader::onInit() {
  for (int i = 0; i < config::TEXTURES_SIZE; i++) {
    _textures[i] = LoadTexture(_textureUrls[i]);
  }
  _log->info("(texture-loader) Loaded textures.");
}

void TextureLoader::onDeinit() {
  for (int i = 0; i < config::TEXTURES_SIZE; i++) {
    UnloadTexture(_textures[i]);
  }
  _log->info("(texture-loader) Unloaded textures.");
}

char **TextureLoader::textureUrls() { return _textureUrls; };
Texture2D *TextureLoader::textures() { return _textures; };

} // namespace game
  
