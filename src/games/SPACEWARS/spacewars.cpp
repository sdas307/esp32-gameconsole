#include <Adafruit_GFX.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "spaceship.h"
#include "enemy.h"
#include "mainmenu.h"
#include "hiscore.h"

void SpaceWarsInit(void)
{
    spaceship.x = (SCREEN_WIDTH / 2) - SPACESHIP_WIDTH;
    spaceship.y = (SCREEN_HEIGHT - SPACESHIP_HEIGHT) - 4;
    spaceship.speed = 2;
}

void SpaceWarsUpdate(void)
{
    switch (spaceWarsGameState)
    {
    case SPACEWARS_PLAY:
        drawScreenBoundary();
        enemyMove(&enemy);
        drawSpaceship(&enemy);
        spaceshipMove(&spaceship);
        drawSpaceship(&spaceship);
        break;

    case SPACEWARS_HI_SCORE:
        break;

    default:
        break;
    }

    delay(16); // Roughly 60fps
}