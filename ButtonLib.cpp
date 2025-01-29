#include "ButtonLib.h"

Button::Button(int pin, unsigned long debounceDelay, unsigned long longPressDelay)
    : _pin(pin), _debounceDelay(debounceDelay), _longPressDelay(longPressDelay),
      _lastState(HIGH), _currentState(HIGH), _lastDebounceTime(0),
      _pressStartTime(0), _longPressDetected(false) {}

void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
    _lastState = digitalRead(_pin);
}

void Button::update() {
    bool reading = digitalRead(_pin);

    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _currentState) {
            _currentState = reading;

            if (_currentState == LOW) {
                _pressStartTime = millis();
                _longPressDetected = false;
            } else {
                _pressStartTime = 0;
            }
        }
    }

    if (_currentState == LOW && !_longPressDetected && (millis() - _pressStartTime) > _longPressDelay) {
        _longPressDetected = true;
    }

    _lastState = reading;
}

bool Button::isPressed() {
    return _currentState == LOW;
}

bool Button::isLongPressed() {
    return _longPressDetected;
}