#include <Arduino.h>
#include "hardware.h"
#include "inputs.h"

bool BUTTON_UP()
{
    if (analogRead(JOY_Y) > 2048)
        return true;

    else
        return false;
}

bool BUTTON_DOWN()
{
    if (analogRead(JOY_Y) < 2048)
        return true;

    else
        return false;
}

bool BUTTON_LEFT()
{
    if (analogRead(JOY_X) > 2048)
        return true;

    else
        return false;
}

bool BUTTON_RIGHT()
{
    if (analogRead(JOY_X) < 2048)
        return true;
    
    else
        return false;
}

bool BUTTON_SELECT()
{
    if (digitalRead(JOY_SEL) == LOW)
        return true;
    
    else
        return false;
}