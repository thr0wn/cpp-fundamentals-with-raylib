#pragma once

constexpr static const float windowWidth = 800.0f;
constexpr static const float windowHeight = 450.0f;

class Entity {
 public:  
  virtual void start() = 0;  
  virtual void update() = 0;  
  virtual void render() = 0;  
  virtual void stop() = 0;  
};
