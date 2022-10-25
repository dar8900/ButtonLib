#include "ButtonLib.h"


BUTTON_MANAGER::BUTTON_MANAGER(int8_t Pin, bool UseEngine, uint16_t LongPressDelay = 0, bool ActiveLow = false)
{
    _pin = Pin;
    if(LongPressDelay != 0)
    {
        _longPressDelay = LongPressDelay;
    }
    _useEngine = UseEngine;
    _activeLow = ActiveLow;
}


button_press_mode BUTTON_MANAGER::getButtonMode()
{
    button_press_mode PressRet = no_press;
    if(_oldStatus != no_press)
    {
        PressRet = _oldStatus;
        _oldStatus = no_press;
    }
    return PressRet;
}

void BUTTON_MANAGER::buttonEngine()
{
    bool Press = false;
    if(_useEngine)
    {
        if(_engineCnt == 0)
        {
            _engineCnt = millis();
        }
        if(millis() - _engineCnt >= __ENGINE_CYCLE)
        {
            _engineCnt = 0;
            Press = (bool)digitalRead(_pin);
            if(Press)
            {
                if(_longPressCnt == 0 && !_longPressed)
                {
                    _longPressCnt = millis();
                }
                if(millis() - _longPressCnt >= _longPressDelay  && !_longPressed)
                {
                    _longPressed = true;
                    _actualMode = long_press;
                    _oldStatus =_actualMode;
                }
                else
                {
                    _actualMode = no_press;
                }
            }
            else
            {
                if(_longPressCnt != 0)
                {
                    _longPressCnt = 0;
                    if(_longPressed)
                    {
                        _longPressed = false;
                        _actualStatus = no_press;
                    }
                    else
                    {
                        _actualMode = short_press;
                    }
                    _oldStatus =_actualMode;
                }
                else
                {
                    _actualMode = no_press;
                }
            }
        }
    }
    else
    {
        Press = (bool)digitalRead(_pin);
        if(Press)
        {
            if(_longPressCnt == 0 && !_longPressed)
            {
                _longPressCnt = millis();
            }
            if(millis() - _longPressCnt >= _longPressDelay  && !_longPressed)
            {
                _longPressed = true;
                _actualMode = long_press;
                _oldStatus =_actualMode;
            }
            else
            {
                _actualMode = no_press;
            }
        }
        else
        {
            if(_longPressCnt != 0)
            {
                _longPressCnt = 0;
                if(_longPressed)
                {
                    _longPressed = false;
                    _actualStatus = no_press;
                }
                else
                {
                    _actualMode = short_press;
                    delay(25);
                }
                _oldStatus =_actualMode;
            }
            else
            {
                _actualMode = no_press;
            }
        }
    }
}