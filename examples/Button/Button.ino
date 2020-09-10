#include <ButtonLib.h>

#define PIN_1   1
#define PIN_2   3
#define PIN_3   5

BUTTON_MANAGER Keyboard;

Vector<uint8_t> Pin;


void setup()
{
    Serial.begin(9600);
    Pin.push_back(PIN_1);
    Pin.push_back(PIN_2);
    Pin.push_back(PIN_3);

    Keyboard.setupKeyboard(Pin);
}

void loop()
{
    uint8_t WichPin = Keyboard.noPinDetected;
    uint8_t ButtonAction = BUTTON_MANAGER::NO_PRESS;
    if(Keyboard.checkKeys(WichPin, ButtonAction))
    {
        if(ButtonAction == BUTTON_MANAGER::PRESSED)
        {
            switch(WichPin)
            {
                case PIN_1:
                    Serial.println("Premuto il pulsante 1");
                    break;
                case PIN_2:
                    Serial.println("Premuto il pulsante 2");
                    break;
                case PIN_3:
                    Serial.println("Premuto il pulsante 3");
                    break;
                default:
                    break;
            }
        }
        else if(ButtonAction == BUTTON_MANAGER::LONG_PRESSED)
        {
            switch(WichPin)
            {
                case PIN_1:
                    Serial.println("Premuto a lungo il pulsante 1");
                    break;
                case PIN_2:
                    Serial.println("Premuto a lungo il pulsante 2");
                    break;
                case PIN_3:
                    Serial.println("Premuto a lungo il pulsante 3");
                    break;
                default:
                    break;
            }
        }
    }
}