#include "ButtonLib.h"


ButtonManager::ButtonManager()
{
}

void ButtonManager::setup(int8_t Pin, uint16_t LongPressDelay, bool ActiveLow)
{
    _pin = Pin;
    if(LongPressDelay != 0)
    {
        _longPressDelay = LongPressDelay;
    }
    _activeLow = ActiveLow;
}

ButtonManager::button_press_mode ButtonManager::getButtonMode()
{
    ButtonManager::button_press_mode PressRet = no_press;
    if(_oldStatus != no_press)
    {
        PressRet = _oldStatus;
        _oldStatus = no_press;
    }
    return PressRet;
}

void ButtonManager::buttonEngine()
{
    bool Press = false;
    if(_engineCnt == 0)
    {
        _engineCnt = millis();
    }
    if(millis() - _engineCnt >= _ENGINE_CYCLE)
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
                _actualStatus = long_press;
                _oldStatus =_actualStatus;
            }
            else
            {
                _actualStatus = no_press;
            }
        }
        else
        {
            if(_longPressCnt != 0 && _actualStatus == no_press)
            {
                _longPressCnt = 0;
                _actualStatus = no_press;
                _actualStatus = short_press;
                _oldStatus =_actualStatus;
            }
            else
            {
                _actualStatus = no_press;
            }
            _longPressed = false;
        }
    }
}