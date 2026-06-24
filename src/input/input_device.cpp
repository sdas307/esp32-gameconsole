#include "input.h"
#include "hardware.h"
#include <Arduino.h>

#ifdef DEVICE_BUILD
void initInput(void)
{
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_SEL, INPUT_PULLUP);
}

bool upPressed(void)
{
    return (digitalRead(BUTTON_UP) == LOW);
}
bool downPressed(void)
{
    return (digitalRead(BUTTON_DOWN) == LOW);
}

bool leftPressed(void)
{
    return (digitalRead(BUTTON_LEFT) == LOW);
}

bool rightPressed(void)
{
    return (digitalRead(BUTTON_RIGHT) == LOW);
}

bool selectPressed(void)
{
    return (digitalRead(BUTTON_SEL) == LOW);
}
#endif