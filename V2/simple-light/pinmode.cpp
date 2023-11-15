#include "pinmode.h"
#include "Arduino.h"

pin_mode_t::pin_mode_t(int pin, int mode) noexcept
  : pin_(pin)
  , mode_(mode)
{
}

void pin_mode_t::set_pin_mode() const noexcept
{
  pinMode(pin_, mode_);
}

int pin_mode_t::analog_read() const noexcept
{
  return analogRead(pin_);
}

void pin_mode_t::analog_write(int value) const noexcept
{
  analogWrite(pin_, value);
}

int pin_mode_t::digital_read() const noexcept
{
  return digitalRead(pin_);
}

void pin_mode_t::digital_write(int value) const noexcept
{
  digitalWrite(pin_, value);
}

void pin_mode_t::pin(int num) noexcept
{
  pin_ = num;
}

int pin_mode_t::pin() const noexcept
{
  return pin_;
}

void pin_mode_t::mode(int new_mode) noexcept
{
  mode_ = new_mode;
}

int pin_mode_t::mode() const noexcept
{
  return mode_;
}
