#include "gamevariables.h"
#include "hardware.h"
#include "input.h"

void pongMainMenu(void)
{
    display.drawRect(0, 0, 128, 64, 1);

    display.setTextSize(1);
    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 - 4);

    /* Rectangle around text for selection
       128/2 = 64, 64 - 6+6+3 = 49, 49 - 4(padding) = 45
       64/2 = 32, 32 - 4 = 28, 28 - 4(padding) = 24 */

    if ((upPressed()) || (downPressed())) // UP or DOWN button press
    {
      if (millis() - lastDebounceTime > DEBOUNCE_DELAY)
      {
        pongAlt *= -1;
        lastDebounceTime = millis();  // Update last debounce time
      }
    }

    if (pongAlt == 1)
      display.drawRect(45, 24, 32, 14, 1);
    else if (pongAlt == -1)
      display.drawRect(45, 24 + 14, 32, 14, 1);

    display.print("PLAY");

    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 + 9);

    display.print("EXIT");

    if (selectPressed()) // SELECT button Press
    {
        pongGameState = PONG_PLAY;
    }
}