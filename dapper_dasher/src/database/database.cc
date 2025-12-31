#include "database/database.h"

namespace game {
Database::Database() {
  gameEmitter->on("game/init", [this](Event event) { onBeforeInit(); });
  gameEmitter->on("game/deinit", [this](Event event) { onAfterDeinit(); });

  gameEmitter->on("database/set", [this](Event event) {
    const auto &pair =
        std::any_cast<std::pair<std::string, std::string>>(event.value);
    set(pair.first, pair.second);
  });

  gameEmitter->on("database/get", [this](Event event) {
    const auto &pair =
        std::any_cast<std::pair<std::string, std::string *>>(event.value);
    get(pair.first, pair.second);
  });

  gameEmitter->on("database/unset", [this](Event event) {
    const auto &key = std::any_cast<std::string>(event.value);
    unset(key);
  });
}

void Database::onBeforeInit() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, databaseLocation, &keyValueDB);
  if (status.ok()) {
    started = true;
    gameEmitter->emit(
        {"log/info",
         std::string("(database) Database initialized.")});
  } else {
    gameEmitter->emit(
        {"log/info", std::string(fmt::format(
                         "(database) Not started due to:\n{}",
                         status.ToString()))});
  }
}

void Database::onAfterDeinit() {
  started = false;
  delete keyValueDB;
  gameEmitter->emit(
      {"log/info",
       std::string("(database) Database deinitialized.")});
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
