#include "database/database-service.h"

namespace game {
DatabaseService::DatabaseService() : GameNode("database-service") {}

void DatabaseService::start() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, databaseLocation, &keyValueDB);
  if (status.ok()) {
    started = true;
  } else {
    logService->log(fmt::format("(database-service) Not started due to:\n{}",
                                status.ToString()));
  }
}

void DatabaseService::stop() { delete keyValueDB; }

void DatabaseService::set(std::string key, std::string value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Put(leveldb::WriteOptions(), key, value);
}

void DatabaseService::get(std::string key, std::string *value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Get(leveldb::ReadOptions(), key, value);
}

void DatabaseService::unset(std::string key) {
  if (started)
    leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
}

DatabaseService *databaseService;
} // namespace game
