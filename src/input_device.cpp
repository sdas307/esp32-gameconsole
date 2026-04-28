#include "input.h"
#include "hardware.h"
#include <Arduino.h>

#ifdef DEVICE_BUILD
void initInput()
{
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_SEL, INPUT_PULLUP);
}

bool upPressed()
{
    return (digitalRead(BUTTON_UP) == LOW);
}
bool downPressed()
{
    return (digitalRead(BUTTON_DOWN) == LOW);
}

bool leftPressed()
{
    return (digitalRead(BUTTON_LEFT) == LOW);
}

bool rightPressed()
{
    return (digitalRead(BUTTON_RIGHT) == LOW);
}

bool selectPressed()
{
    return (digitalRead(BUTTON_SEL) == LOW);
}
#endif