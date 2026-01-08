#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "fmt/format.h"
#include "leveldb/db.h"
#include "log/log.h"
#include <any>
#include <map>
#include <memory>

namespace game {
class Database {
  leveldb::DB *keyValueDB;
  std::string databaseLocation = config::DATABASE_LOCATION;
  bool started = false;
  Log *log = AsyncPointer::get<Log>();
  Emitter *emitter = AsyncPointer::get<Emitter>();

public:
  Database() {
    emitter->on("game/init", [this](Event event) { onBeforeInit(); });
    emitter->on("game/deinit", [this](Event event) { onAfterDeinit(); });
  }

  void onBeforeInit() {
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status =
        leveldb::DB::Open(options, databaseLocation, &keyValueDB);
    if (status.ok()) {
      started = true;
      log->info("(database) Database initialized.");
    } else {
      log->info(std::string(fmt::format("(database) Not started due to:\n{}",
                                        status.ToString())));
    }
  }

  void onAfterDeinit() {
    started = false;
    delete keyValueDB;
    log->info("(database) Database deinitialized.");
  }

  void set(std::string key, std::string value) {
    if (started) {
      leveldb::Status status =
          keyValueDB->Put(leveldb::WriteOptions(), key, value);
    }
  }

  void get(std::string key, std::string *value) {
    if (started) {
      leveldb::Status status =
          keyValueDB->Get(leveldb::ReadOptions(), key, value);
    }
  }

  void unset(std::string key) {
    if (started) {
      leveldb::Status status = keyValueDB->Delete(leveldb::WriteOptions(), key);
    }
  }
};
} // namespace game
