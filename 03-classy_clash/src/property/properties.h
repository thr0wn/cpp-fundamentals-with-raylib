#pragma once
#include "property/property.h"
#include <string>
#include <map>
#include <variant>

namespace game {
  class Properties {
  private:
    std::map<std::string, Property> _properties;
  public:
    void set(std::string key, Property property);

    template <typename T>
    T* get(std::string key) {
      return std::get_if<T>(&_properties[key]);  
    }
  };
}
