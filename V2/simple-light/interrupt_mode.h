#pragma once
#include "Arduino.h"

enum interrupt_mode_t
{
  low = LOW,
  change = CHANGE,
  rising = RISING,
  falling = FALLING,
  high = HIGH
};
