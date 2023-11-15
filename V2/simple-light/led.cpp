#include "led.h"
#include "Arduino.h"

led_t::led_t(const pin_mode_t& pin) noexcept
  : pin_(pin)
{
}

void led_t::turn_on() const noexcept
{
  pin_.digital_write(HIGH);
}

void led_t::turn_off() const noexcept
{
  pin_.digital_write(LOW);
}
