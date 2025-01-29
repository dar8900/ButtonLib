#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin, unsigned long debounceDelay = 50, unsigned long longPressDelay = 1000);
    void begin();
    void update();
    bool isPressed();
    bool isLongPressed();

private:
    int _pin;
    unsigned long _debounceDelay;
    unsigned long _longPressDelay;
    bool _lastState;
    bool _currentState;
    unsigned long _lastDebounceTime;
    unsigned long _pressStartTime;
    bool _longPressDetected;
};

#endif