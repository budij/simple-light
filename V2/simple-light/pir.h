#pragma once
#include "pinmode.h"

class pir_t
{
public:
  pir_t(const pin_mode_t& pin) noexcept;
  ~pir_t() noexcept = default;

public:
  bool is_triggered() const noexcept;

private:
  const pin_mode_t& pin_;
};
