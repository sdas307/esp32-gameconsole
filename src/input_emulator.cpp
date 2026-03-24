#include "input.h"
#include "hardware.h"
#include <Arduino.h>

void initInput()
{

}

bool upPressed()
{
    return (analogRead(JOY_Y) > IDLE_JOYSTICK_VALUE);
}

bool downPressed()
{
    return (analogRead(JOY_Y) < IDLE_JOYSTICK_VALUE);
}

bool leftPressed()
{
    return (analogRead(JOY_X) > IDLE_JOYSTICK_VALUE);
}

bool rightPressed()
{
    return (analogRead(JOY_X) < IDLE_JOYSTICK_VALUE);
}

bool selectPressed()
{
    return (digitalRead(JOY_SEL) == LOW);
}