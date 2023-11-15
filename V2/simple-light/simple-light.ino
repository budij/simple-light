/*
 * To upload to arduino pro micro:
 * * Make sure the reset pin is set to low to reset the bootloader (connect it to GND)
 * * Start the upload process, and it will start to compile the code first
 * * When it's about to finish compiling, remove the wire from GND to reset pin, to let arduino start up
 * * It should be timed so that the upload happens within 8 seconds of the reset pin is not connected to GND
 */
#define USE_SERIAL
#define USE_SLEEP

// Remove the approprirate undef to enable the preprocessor
#undef USE_SERIAL
//#undef USE_SLEEP

#include "led.h"
#include "low_power.h"
#include "pinmode.h"
#include "sensor.h"
#include "utilities.h"

const int light_threshold = 650;
const int pir_duration = 20;
const int light_pin_num = 18;
const int light_sensor_pin_num = A7;
const int pir_sensor_pin_num = 3;

pin_mode_t light_pin(light_pin_num, OUTPUT);
pin_mode_t light_sensor_pin(light_sensor_pin_num, INPUT);
pin_mode_t pir_sensor_pin(pir_sensor_pin_num, INPUT_PULLUP);

low_power_t low_power(pir_sensor_pin_num, interrupt_mode_t::high, sleep_mode_t::power_down);
led_t led(light_pin);
sensor_t<pir_duration, light_threshold> sensor(pir_sensor_pin, light_sensor_pin);

void setup() {
  light_pin.set_pin_mode();
  light_sensor_pin.set_pin_mode();
  pir_sensor_pin.set_pin_mode();

#if defined(USE_SLEEP)
  low_power.init();
#endif

#if defined(USE_SERIAL)
  Serial.begin(9600);
#endif
}

void loop() {
#if defined(USE_SERIAL)
  Serial << "Light threshold: " << light_threshold << "\n";
  Serial << "Light: " << light_sensor_pin.analog_read() << "\n";
  Serial << "PIR: " << pir_sensor_pin.digital_read() << "\n";
#endif

  if (sensor.check_triggered())
  {
    led.turn_on();
    delay(1000);
  }
  else
  {
    led.turn_off();
#if defined(USE_SLEEP)
    low_power.sleep();
#else
    delay(1000);
#endif
  }
}
