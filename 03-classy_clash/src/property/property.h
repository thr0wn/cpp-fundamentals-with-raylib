#pragma once
#include <variant>
#include <string>

namespace game {
  using Property = std::variant<int, float, std::string>;
}
