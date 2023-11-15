#pragma once
#include "interrupt_mode.h"
#include "sleep_mode.h"

class low_power_t
{
public:
  low_power_t(int interrupt_pin) noexcept;
  low_power_t(int interrupt_pin, interrupt_mode_t mode, sleep_mode_t sleep_mode) noexcept;
  ~low_power_t() noexcept = default;

public:
  void init() noexcept;
  void sleep() noexcept;

private:
  void setup_interrupt() const noexcept;

private:
  int pin_;
  interrupt_mode_t mode_;
  sleep_mode_t sleep_mode_;
};
