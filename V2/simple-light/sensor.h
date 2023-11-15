#pragma once
#include "pir.h"
#include "light.h"
#include "pinmode.h"

template <int Duration, int LightThreshold>
class sensor_t
{
public:
  sensor_t(const pin_mode_t& pir_pin, const pin_mode_t& light_pin) noexcept;
  ~sensor_t() noexcept = default;

public:
  bool check_triggered() noexcept;
  bool is_triggered() const noexcept;
  bool is_pir_triggered() const noexcept;
  bool is_light_triggered() const noexcept;

#if defined(DEBUG)
  const pir_t& pir() const noexcept;
  const light_t<LightThreshold> light() const noexcept;
#endif

private:
  pir_t pir_;
  light_t<LightThreshold> light_;
  int triggered_duration_;
};

template <int Duration, int LightThreshold>
sensor_t<Duration, LightThreshold>::sensor_t(const pin_mode_t& pir_pin, const pin_mode_t& light_pin) noexcept
  : pir_(pir_pin)
  , light_(light_pin)
  , triggered_duration_(0)
{
}

template <int Duration, int LightThreshold>
bool sensor_t<Duration, LightThreshold>::check_triggered() noexcept
{
  if (triggered_duration_ > 0)
  {
    --triggered_duration_;
  }

  if (is_pir_triggered() && is_light_triggered())
  {
    triggered_duration_ = Duration;
  }

  return is_triggered();
}

template <int Duration, int LightThreshold>
bool sensor_t<Duration, LightThreshold>::is_triggered() const noexcept
{
  return triggered_duration_ > 0;
}

template <int Duration, int LightThreshold>
bool sensor_t<Duration, LightThreshold>::is_pir_triggered() const noexcept
{
  return pir_.is_triggered();
}

template <int Duration, int LightThreshold>
bool sensor_t<Duration, LightThreshold>::is_light_triggered() const noexcept
{
  return light_.above_threshold();
}

#if defined(DEBUG)
template <int Duration, int LightThreshold>
const pir_t& sensor_t<Duration, LightThreshold>::pir() const noexcept
{
  return pir_;
}

template <int Duration, int LightThreshold>
const light_t<LightThreshold> sensor_t<Duration, LightThreshold>::light() const noexcept
{
  return light_;
}
#endif
