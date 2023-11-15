#include "pir.h"

pir_t::pir_t(const pin_mode_t& pin) noexcept
  : pin_(pin)
{
}

bool pir_t::is_triggered() const noexcept
{
  return pin_.digital_read() > 0;
}
