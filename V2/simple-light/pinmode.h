#pragma once

class pin_mode_t
{
public:
  pin_mode_t(int pin, int mode) noexcept;
  ~pin_mode_t() noexcept = default;

public:
  void set_pin_mode() const noexcept;
  int analog_read() const noexcept;
  void analog_write(int value) const noexcept;
  int digital_read() const noexcept;
  void digital_write(int value) const noexcept;

  void pin(int num) noexcept;
  int pin() const noexcept;
  void mode(int new_mode) noexcept;
  int mode() const noexcept;

private:
  int pin_;
  int mode_;
};
