#include "database/database-service.hpp"

namespace databaseService {
namespace {
leveldb::DB *keyValueDB;
std::string databaseLocation = config::DATABASE_LOCATION;
bool started = false;
} // namespace

void start() {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status =
      leveldb::DB::Open(options, databaseLocation, &keyValueDB);
  if (status.ok()) {
    logService::log("(database) Started");
    started = true;
  } else {
    logService::log(
        fmt::format("(database) Not started due to:\n{}", status.ToString()));
  }
}
void stop() {
  delete keyValueDB;
  logService::log("(database) Stopped");
}  

void set(std::string key, std::string value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Put(leveldb::WriteOptions(), key, value);
}
void get(std::string key, std::string *value) {
  if (started)
    leveldb::Status status =
        keyValueDB->Get(leveldb::ReadOptions(), key, value);
}
void unset(std::string key) {
  if (started)
    leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
}
} // namespace databaseService
