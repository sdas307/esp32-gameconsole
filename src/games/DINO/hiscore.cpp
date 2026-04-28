#include "hiscore.h"
#include "gamevariables.h"
#include "hardware.h"
#include "input.h"

void hiScore()
{
    if (selectPressed())
        dinoGameState = PLAY;

    display.setTextSize(1);
    display.setTextColor(DISPLAY_WHITE);

    display.setCursor(20, 20);
    display.print("Score:");

    display.setCursor(58, 20);
    display.print(scoreText);

    display.setCursor(20, 36);
    display.print("Press Select");

    display.setCursor(20, 46);
    display.print("to Restart...");
}