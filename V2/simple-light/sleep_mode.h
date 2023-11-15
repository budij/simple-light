#pragma once
#include <avr/sleep.h>

enum sleep_mode_t
{
  idle = SLEEP_MODE_IDLE,
  adc = SLEEP_MODE_ADC,
  power_save = SLEEP_MODE_PWR_SAVE,
  standby = SLEEP_MODE_STANDBY,
  power_down = SLEEP_MODE_PWR_DOWN
};
