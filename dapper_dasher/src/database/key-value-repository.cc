#include "database/key-value-repository.h"

namespace game {
KeyValueRepository::KeyValueRepository() {
  gameEmitter->on("game/init", [this](Event event) { onBeforeInit(); });
  gameEmitter->on("game/deinit", [this](Event event) { onAfterDeinit(); });
}

void KeyValueRepository::onBeforeInit() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, databaseLocation, &keyValueDB);
  if (status.ok()) {
    started = true;
    logService->info("(key-value-repository) KeyValueRepository initialized.");
  } else {
    logService->info(fmt::format(
        "(key-value-repository) Not started due to:\n{}", status.ToString()));
  }
}

void KeyValueRepository::onAfterDeinit() {
  started = false;
  delete keyValueDB;
  logService->info("(key-value-repository) KeyValueRepository deinitialized.");
}

void KeyValueRepository::set(std::string key, std::string value) {
  if (started) {
    leveldb::Status status =
        keyValueDB->Put(leveldb::WriteOptions(), key, value);
  }
}

void KeyValueRepository::get(std::string key, std::string *value) {
  if (started) {
    leveldb::Status status =
        keyValueDB->Get(leveldb::ReadOptions(), key, value);
  }
}

void KeyValueRepository::unset(std::string key) {
  if (started) {
    leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
  }
}

std::unique_ptr<KeyValueRepository> keyValueRepository;
} // namespace game
