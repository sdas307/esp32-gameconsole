#include <Adafruit_GFX.h>
#include "hardware.h"
#include "input/input.h"
#include "gamevariables.h"
#include "spaceship.h"
#include "enemy.h"
#include "mainmenu.h"
#include "hiscore.h"

void SpaceWarsInit(void)
{
    Spaceship.x = (SCREEN_WIDTH / 2) - SPACESHIP_WIDTH;
    Spaceship.y = (SCREEN_HEIGHT - SPACESHIP_HEIGHT) - 4;
    Spaceship.speed = 2;
}

void SpaceWarsUpdate(void)
{
    switch (spaceWarsGameState)
    {
    case SPACEWARS_PLAY:
        drawScreenBoundary();

        drawSprite(&Spaceship);
        spaceshipMove(&Spaceship);

        drawSprite(&Jango);
        enemyMove(&Jango);
        break;

    case SPACEWARS_HI_SCORE:
        break;

    default:
        break;
    }

    delay(16); // Roughly 60fps
}