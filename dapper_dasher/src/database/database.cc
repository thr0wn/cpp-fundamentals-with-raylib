#include "database/database.h"

namespace game {
Database::Database() {
  gameEmitter->on("game/init", [this](Event event) { onBeforeInit(); });
  gameEmitter->on("game/deinit", [this](Event event) { onAfterDeinit(); });
}

void Database::onBeforeInit() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, databaseLocation, &keyValueDB);
  if (status.ok()) {
    started = true;
    log->info("(database) Database initialized.");
  } else {
    log->info(std::string(
        fmt::format("(database) Not started due to:\n{}", status.ToString())));
  }
}

void Database::onAfterDeinit() {
  started = false;
  delete keyValueDB;
  log->info("(database) Database deinitialized.");
}

void Database::set(std::string key, std::string value) {
  if (started) {
    leveldb::Status status =
        keyValueDB->Put(leveldb::WriteOptions(), key, value);
  }
}

void Database::get(std::string key, std::string *value) {
  if (started) {
    leveldb::Status status =
        keyValueDB->Get(leveldb::ReadOptions(), key, value);
  }
}

void Database::unset(std::string key) {
  if (started) {
    leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
  }
}

} // namespace game
