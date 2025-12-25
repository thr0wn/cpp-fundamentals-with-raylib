#include "database/key-value-repository.h"

namespace game {
KeyValueRepository::KeyValueRepository() : GameNode("database-service") {}

void KeyValueRepository::start() {
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

void KeyValueRepository::stop() {
  started = false;
  delete keyValueDB;
}

void KeyValueRepository::set(std::string key, std::string value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Put(leveldb::WriteOptions(), key, value);
}

void KeyValueRepository::get(std::string key, std::string *value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Get(leveldb::ReadOptions(), key, value);
}

void KeyValueRepository::unset(std::string key) {
  if (started)
    leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
}

std::unique_ptr<KeyValueRepository> keyValueRepository;
} // namespace game
