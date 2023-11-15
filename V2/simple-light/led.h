#pragma once
#include "pinmode.h"

class led_t
{
public:
  led_t(const pin_mode_t& pin) noexcept;
  ~led_t() noexcept = default;

public:
  void turn_on() const noexcept;
  void turn_off() const noexcept;

private:
  const pin_mode_t& pin_;
};
