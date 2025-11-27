#pragma once
#include "raylib.h"
#include "raymath.h"

class Timer {
  double startTime = 0;
  double endTime = 0;

public:
  Timer(double endTime);
  void start();
  bool isActive();
  double elapsed();
};

class Entity {
 public:  
  virtual void start();  
  virtual void update();  
  virtual void render();  
  virtual void stop();  
};

class Player {
  Vector2 position;  
  float width = 50.0f;
  float height = 80.0f;

  const float initialVelocity = 10.0f;
  float velocity = initialVelocity;
  float jumpVelocity = -10.0f;
  Timer jumpTimer{.25f};

public:
  void start();
  void update();
  void render();
  void stop();
};

class Game {
  Player player{};

public:
  constexpr static const float windowWidth = 800.0f;
  constexpr static const float windowHeight = 450.0f;
  void start();
  void update();
  void render();
  void stop();
};
