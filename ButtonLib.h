#ifndef BUTTON_LIB_H
#define BUTTON_LIB_H
#include <Arduino.h>
#include <vector>
#include <stdint.h>
using namespace std;

class BUTTON_MANAGER
{
    private:
        uint8_t buttonActivationModality = ACTIVE_HIGH;
        vector<uint8_t> pins;
        uint8_t nPins;
        vector<uint32_t>elapsedPressTime;
        vector<bool>wasLongButtonPress;
        uint32_t longPressTime = 1000;
    public:
        enum
        {
            PRESSED = 0,
            LONG_PRESSED,
            NO_PRESS
        }
        enum
        {
            ACTIVE_LOW = 0,
            ACTIVE_HIGH
        };
        uint8_t noPinDetected;
        void setupKeyboard(vector<uint8_t> Pins, uint8_t Modality = ACTIVE_HIGH, uint32_t LongPressTime = 1000);
        bool checkKeys(uint8_t &ButtonPressed, uint8_t &Action);
};

#endif