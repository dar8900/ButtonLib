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

}

void BUTTON_MANAGER::buttonEngine()
{
    bool Press = false;
    if(_useEngine)
    {
        if(_longPressCnt == 0)
        {
            _longPressCnt = millis();
        }
        if(_modeButtonEngineTimer.isOver(true))
        {
            Press = (bool)digitalRead(_pin);
            if(Press)
            {
                if(!_longPressTimer.isRunning() && !_longPressed)
                {
                    _longPressTimer.start(_longPressDelay);
                }
                if(_longPressTimer.isOver() && !_longPressed)
                {
                    _longPressed = true;
                    _actualMode = long_press;
                    _lastMode =_actualMode;
                    Debug.logDebug("Pressione prolungata");
                }
                else
                {
                    _actualMode = no_press;
                }
            }
            else
            {
                if(_longPressTimer.isRunning())
                {
                    _longPressTimer.stop();
                    _actualMode = short_press;
                    _lastMode =_actualMode;
                    Debug.logDebug("Pressione breve");
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

    }
}