#include <stdint.h>
#include "hardware.h"
#include "gamevariables.h"

void snakeHiScore()
{
    display.setTextSize(1);
    display.setTextColor(DISPLAY_WHITE);

    display.setCursor(SCREEN_WIDTH/2 - 55, SCREEN_HEIGHT/2 - 12);
    display.print("Your Score:");

    display.setTextSize(2);
    display.setCursor(SCREEN_WIDTH/2 - 55, SCREEN_HEIGHT/2);
    display.print(snakeScore);
}