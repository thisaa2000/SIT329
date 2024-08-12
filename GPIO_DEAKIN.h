#ifndef GPIO_DEAKIN_H
#define GPIO_DEAKIN_H

#include <Arduino.h>

class GPIO_DEAKIN {
public:
    // Configure a group of GPIO pins as either inputs or outputs
    void configure_pins(const uint8_t* pinArray, uint8_t numPins, bool asOutput);

    // Control the pins to display a specified pattern
    bool GPIO_Display_Pattern(const uint8_t* pinArray, uint8_t numPins, uint8_t pattern);

    // Control pins to turn on and off sequentially
    //void run_lights(uint8_t* pinArray, uint8_t numPins, unsigned long duration);
    void run_lights(const uint8_t* pinArray, uint8_t numPins, unsigned long duration);

private:
    void set_pins(const uint8_t* pinArray, uint8_t numPins, uint8_t pattern, bool state);
};

#endif // GPIO_DEAKIN_H
