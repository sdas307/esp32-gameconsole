#include "input.h"
#include "hardware.h"
#include <Arduino.h>

void initInput(void)
{

}

bool upPressed(void)
{
    return (analogRead(JOY_Y) > IDLE_JOYSTICK_VALUE);
}

bool downPressed(void)
{
    return (analogRead(JOY_Y) < IDLE_JOYSTICK_VALUE);
}

bool leftPressed(void)
{
    return (analogRead(JOY_X) > IDLE_JOYSTICK_VALUE);
}

bool rightPressed(void)
{
    return (analogRead(JOY_X) < IDLE_JOYSTICK_VALUE);
}

bool selectPressed(void)
{
    return (digitalRead(JOY_SEL) == LOW);
}