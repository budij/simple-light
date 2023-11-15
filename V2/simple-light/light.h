#pragma once
#include "pinmode.h"

template <int Threshold>
class light_t
{
public:
  light_t(const pin_mode_t& pin) noexcept;
  ~light_t() noexcept = default;

public:
  bool above_threshold() const noexcept;

private:
  const pin_mode_t& pin_;
};

template <int Threshold>
light_t<Threshold>::light_t(const pin_mode_t& pin) noexcept
  : pin_(pin)
{
}

template <int Threshold>
bool light_t<Threshold>::above_threshold() const noexcept
{
  return pin_.analog_read() > Threshold;
}
