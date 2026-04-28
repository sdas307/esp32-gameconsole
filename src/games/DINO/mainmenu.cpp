#include <Adafruit_GFX.h>
#include <stdint.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "mainmenu.h"
 
void dinoMainMenu()
{
    display.setTextSize(1);
    display.setTextColor(DISPLAY_WHITE);

    if (upPressed() || downPressed())
    {
        if (millis() - dinoLastDebounceTime > DINO_DEBOUNCE_DELAY)
        {
            dinoAlt *= -1;
            dinoLastDebounceTime = millis();  // Update last debounce time
        }
    }

    if (dinoAlt == 1)
    {
        display.drawRect(SCREEN_WIDTH/2 - 18, SCREEN_HEIGHT/2 - 6, 29, 12, DISPLAY_WHITE);
    }
    else if (dinoAlt == -1)
    {
        display.drawRect(SCREEN_WIDTH/2 - 18, SCREEN_HEIGHT/2 + 6, 29, 12, DISPLAY_WHITE);
    }

    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 - 4);
    display.print("PLAY");
    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 + 9);
    display.print("EXIT");

    if (selectPressed())
    {
        dinoGameState = PLAY;
    }
}