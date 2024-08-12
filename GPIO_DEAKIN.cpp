#include "GPIO_DEAKIN.h"

// Configure a group of GPIO pins as either inputs or outputs
void GPIO_DEAKIN::configure_pins(const uint8_t* pinArray, uint8_t numPins, bool asOutput) {
    for (uint8_t i = 0; i < numPins; i++) {
        pinMode(pinArray[i], asOutput ? OUTPUT : INPUT);
    }
}

// Set the state of the pins based on the pattern
void GPIO_DEAKIN::set_pins(const uint8_t* pinArray, uint8_t numPins, uint8_t pattern, bool state) {
    for (uint8_t i = 0; i < numPins; i++) {
        if (pattern & (1 << i)) {
            digitalWrite(pinArray[i], state ? HIGH : LOW);
        }
    }
}

// Display a pattern on the pins
bool GPIO_DEAKIN::GPIO_Display_Pattern(const uint8_t* pinArray, uint8_t numPins, uint8_t pattern) {
    if (numPins > 6) return false; // Limit to 6 pins
    set_pins(pinArray, numPins, pattern, true);
    return true;
}

// Control pins to turn on and off sequentially
void GPIO_DEAKIN::run_lights(const uint8_t* pinArray, uint8_t numPins, unsigned long duration) {
    // Implementation of the run_lights method
    for (uint8_t i = 0; i < numPins; i++) {
        pinMode(pinArray[i], OUTPUT);
    }
  
    while (true) {
        // Turn on LEDs in sequence
        for (uint8_t i = 0; i < numPins; i++) {
            digitalWrite(pinArray[i], HIGH);
            delay(duration);
            digitalWrite(pinArray[i], LOW);
        }
      
        // Turn off LEDs in sequence
        for (int8_t i = numPins - 1; i >= 0; i--) {
            digitalWrite(pinArray[i], HIGH);
            delay(duration);
            digitalWrite(pinArray[i], LOW);
        }
    }
}
