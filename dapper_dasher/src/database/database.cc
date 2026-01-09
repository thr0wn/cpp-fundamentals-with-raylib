#include "database/database.h"

namespace game {
Database::Database() {
  _emitter->on("game/init", [this](Event event) { onBeforeInit(); });
  _emitter->on("game/deinit", [this](Event event) { onAfterDeinit(); });
}

void Database::onBeforeInit() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, _databaseLocation, &_keyValueDB);
  if (status.ok()) {
    _started = true;
    _log->info("(database) Database initialized.");
  } else {
    _log->info(std::string(
        fmt::format("(database) Not started due to:\n{}", status.ToString())));
  }
}

void Database::onAfterDeinit() {
  _started = false;
  delete _keyValueDB;
  _log->info("(database) Database deinitialized.");
}

void Database::set(std::string key, std::string value) {
  if (_started) {
    leveldb::Status status =
        _keyValueDB->Put(leveldb::WriteOptions(), key, value);
  }
}

void Database::get(std::string key, std::string *value) {
  if (_started) {
    leveldb::Status status =
        _keyValueDB->Get(leveldb::ReadOptions(), key, value);
  }
}

void Database::unset(std::string key) {
  if (_started) {
    leveldb::Status status = _keyValueDB->Delete(leveldb::WriteOptions(), key);
  }
}

} // namespace game
