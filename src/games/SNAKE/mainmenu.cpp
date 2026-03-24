#include <Adafruit_GFX.h>
#include <stdint.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "mainmenu.h"
 
void snakeMainMenu()
{
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (upPressed() || downPressed())
    {
        if (millis() - snakeLastDebounceTime > SNAKE_DEBOUNCE_DELAY)
        {
            snakeAlt *= -1;
            snakeLastDebounceTime = millis();  // Update last debounce time
        }
    }

    if (snakeAlt == 1)
    {
        display.drawRect(SCREEN_WIDTH/2 - 18, SCREEN_HEIGHT/2 - 6, 29, 12, WHITE);
    }
    else if (snakeAlt == -1)
    {
        display.drawRect(SCREEN_WIDTH/2 - 18, SCREEN_HEIGHT/2 + 6, 29, 12, WHITE);
    }

    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 - 4);
    display.print("PLAY");
    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 + 9);
    display.print("EXIT");

    if (selectPressed())
    {
        gameState = PLAY;
    }
}