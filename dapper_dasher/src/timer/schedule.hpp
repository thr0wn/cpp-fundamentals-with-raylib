#pragma once
#include "timer.hpp"
#include <functional>
#include <list>

typedef std::function<void(void)> VoidFunction;

class Schedule {
public:  
  Timer *timer = NULL;
  VoidFunction fun;
  bool isExecuted;
  bool isRepetable; 
};
