#pragma once
#include "config/config.hpp"
#include "fmt/format.h"
#include "leveldb/db.h"
#include "log/log-service.hpp"

namespace databaseService {
// start db connections
void start();
// stop db connections
void stop();

// key-value database: set
void set(std::string key, std::string value);
// key-value database: get
void get(std::string key, std::string *value);
// key-value database: unset
void unset(std::string key);
} // namespace databaseService
