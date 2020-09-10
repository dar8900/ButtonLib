#include <ButtonLib.h>

#define PIN_1   1
#define PIN_2   3
#define PIN_3   5

BUTTON_MANAGER Keyboard;

vector<uint8_t> Pin;


void setup()
{
    Pin.push_back(PIN_1);
    Pin.push_back(PIN_2);
    Pin.push_back(PIN_3);

    Keyboard.setupKeyboard(Pin);
}

void loop()
{
    uint8_t WichPin = BUTTON_MANAGER::noPinDetected;
    uint8_t ButtonAction = BUTTON_MANAGER::NO_PRESS;
    if(Keyboard.checkKeys(WichPin, ButtonAction))
    {
        switch(WichPin)
        {
            case PIN_1:
                break;
            case PIN_2:
                break;
            case PIN_3:
                break;
            default:
                break;
        }
    }
}