#ifndef BUTTON_LIB_H
#define BUTTON_LIB_H
#include <Arduino.h>
#include <stdint.h>

class BUTTON_MANAGER
{
    typedef enum
    {
        short_press = 0,
        long_press,
        no_press
    }button_press_mode;

    public:
        BUTTON_MANAGER(int8_t Pin, bool UseEngine,uint16_t LongPressDelay = 0, bool ActiveLow = false);
        button_press_mode getButtonMode();
        void buttonEngine();

    private:
        const uint16_t _LONG_PRESS_DELAY_DFLT = 1500; // in ms
        int8_t _pin = -1;
        bool _activeLow = false;
        uint16_t _longPressDelay = _LONG_PRESS_DELAY_DFLT;
        uint32_t _longPressCnt;
        bool _useEngine = false;
        button_press_mode _actualStatus = no_press;
};

#endif