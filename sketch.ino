
#include <Arduino.h>

int counter = 0;

void setup() {

  // Pin 8, 9, 10, 11 = OUTPUT
  // Pin 12 = INPUT
  DDRB = (DDRB & 0b11101111) | 0b00001111;

  // Enable internal pull-up for Pin 12
  // Turn OFF all LEDs initially
  PORTB = (PORTB & 0b11100000) | 0b00010000;
}

void loop() {

  // Read Push Button using PINB
  if (!(PINB & 0b00010000)) {

    delay(50);  // Debouncing

    // Check button again
    if (!(PINB & 0b00010000)) {

      // Increment counter (0 to 15)
      counter = (counter + 1) % 16;

      // Display binary value on 4 LEDs
      // Single PORTB register write
      PORTB = (PORTB & 0b11110000) | (counter & 0b00001111);

      // Wait until button is released
      while (!(PINB & 0b00010000)) {
      }

      delay(50);
    }
  }
}
