#ifndef BUTTON_LIB_H
#define BUTTON_LIB_H
#include <Arduino.h>
#include <stdint.h>

class BUTTON_MANAGER
{
    public:
        typedef enum
        {
            short_press = 0,
            long_press,
            no_press
        }button_press_mode;

        BUTTON_MANAGER();
        void setup(int8_t Pin, uint16_t LongPressDelay = 0, bool ActiveLow = false)
        button_press_mode getButtonMode();
        void buttonEngine();

    private:
        const uint16_t _LONG_PRESS_DELAY_DFLT = 1500; // in ms
        const uint16_t _ENGINE_CYCLE = 20; // in ms
        int8_t _pin = -1;
        bool _activeLow = false;
        uint16_t _longPressDelay = _LONG_PRESS_DELAY_DFLT;
        uint32_t _longPressCnt = 0;
        uint32_t _engineCnt = 0;
        bool _longPressed = false;
        button_press_mode _actualStatus = no_press;
        button_press_mode _oldStatus = no_press;
};

#endif