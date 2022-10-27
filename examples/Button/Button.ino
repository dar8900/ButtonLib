#include <ButtonLib.h>

#define PIN_1   1
#define PIN_2   3
#define PIN_3   5

#define MAX_KEYBOARD_KEYS   3

ButtonManager Keyboard[MAX_KEYBOARD_KEYS];

void setup()
{
    Serial.begin(9600);
    int8_t Pins[MAX_KEYBOARD_KEYS] = {
        PIN_1,
        PIN_2,
        PIN_3
    };

    for(int i = 0; i < MAX_KEYBOARD_KEYS; i++)
    {
        Keyboard[i].setup(Pins[i], 1500, true);
    }
}

int i = 0;

void loop()
{
    if(Keyboard[i].getButtonMode() == ButtonManager::button_press_mode::short_press)
    {
        Serial.println("Short press of pin " + String(Pins[i]));
    }
    else if(Keyboard[i].getButtonMode() == ButtonManager::button_press_mode::long_press)
    {
        Serial.println("Long press of pin " + String(Pins[i]));
    }
    Keyboard[i].buttonEngine();    
    if(i < MAX_KEYBOARD_KEYS - 1)
    {
        i++;
    }
    else
    {
        i = 0;
    }
}