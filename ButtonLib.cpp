#include "ButtonLib.h"

void BUTTON_MANAGER::setupKeyboard(Vector<uint8_t> Pins, uint8_t Modality, uint32_t LongPressTime)
{
    pins = Pins;
    nPins = pins.size();
    buttonActivationModality = Modality;
    noPinDetected = pins.size() + 1;
    longPressTime = LongPressTime;
    for(int i = 0; i < pins.size() ; i++)
    {
        pinMode(pins[i], INPUT);
        elapsedPressTime.push_back(0);
        wasLongButtonPress.push_back(false);
    }
}

bool BUTTON_MANAGER::checkKeys(uint8_t &ButtonPressed, uint8_t &Action)
{
    bool KeyboardPressed = false, LongPress = false;
    Action = NO_PRESS;
    ButtonPressed = noPinDetected;
    uint8_t PinRead = 0;
    for(int Key = 0; Key < pins.size(); Key++)
    {
        PinRead = digitalRead(pins[Key]);
        if(PinRead == buttonActivationModality)
        {
            ButtonPressed = Key;
            KeyboardPressed = true;
            break;
        }
    }
    if(ButtonPressed != noPinDetected)
    {
        elapsedPressTime[ButtonPressed] = millis();
        while(PinRead == buttonActivationModality)
        {
            PinRead = digitalRead(pins[ButtonPressed]);
            if(millis() - elapsedPressTime[ButtonPressed] >= longPressTime)
            {
                LongPress = true;
                break;
            }
        }
        if(LongPress)
        {
            Action = LONG_PRESSED;
            wasLongButtonPress[ButtonPressed] = true;
        }
        else
        {
            if(!wasLongButtonPress[ButtonPressed])
            {
                Action = PRESSED;
            }
            else
            {
                wasLongButtonPress[ButtonPressed] = false;
            }
        }   
        elapsedPressTime[ButtonPressed] = 0;     
        delay(25);
    }
    return KeyboardPressed;
}