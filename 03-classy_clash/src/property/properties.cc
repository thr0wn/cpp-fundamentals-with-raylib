#include "property/properties.h"

namespace game {
  void Properties::set(std::string key, Property property) {
    _properties[key] = property;
  }
}
