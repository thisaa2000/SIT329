#include <Arduino.h>
#include "GPIO_DEAKIN.h"

// Create an instance of GPIO_DEAKIN
GPIO_DEAKIN gpio;

// Define the pin numbers for LEDs
const uint8_t ledPins[] = {2, 3, 4, 5, 6, 7}; // Adjust as needed
const uint8_t numPins = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
    // Configure pins as outputs
    gpio.configure_pins(ledPins, numPins, true);

    // Test pattern: turn on LEDs 1 and 3
    gpio.GPIO_Display_Pattern(ledPins, numPins, 0b00000101);

    // Run lights effect
    // Adjust duration for your preference (in milliseconds)
    gpio.run_lights(ledPins, numPins, 500); // 500 ms delay
}

void loop() {
    // No need to do anything here; the `run_lights` method will handle the blinking
}
