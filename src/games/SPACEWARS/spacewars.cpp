#include <Adafruit_GFX.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "mainmenu.h"
#include "hiscore.h"

void SpaceWarsInit()
{
    spaceshipPosX = (SCREEN_WIDTH / 2) - SPACESHIP_WIDTH;
    spaceshipPosY = (SCREEN_HEIGHT - SPACESHIP_HEIGHT) - 4;
}

void SpaceWarsUpdate()
{
    switch (spaceWarsGameState)
    {
    case PLAY:
        spaceshipMove();
        drawSpaceship();
        break;

    case HI_SCORE:
        break;

    default:
        break;
    }

    delay(16); // Roughly 60fps
}