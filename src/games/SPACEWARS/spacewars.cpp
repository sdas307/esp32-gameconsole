#include <Adafruit_GFX.h>
#include "hardware.h"
#include "input/input.h"
#include "gamevariables.h"
#include "spaceship.h"
#include "enemy.h"
#include "bullet.h"
#include "mainmenu.h"
#include "hiscore.h"

void SpaceWarsInit(void)
{
    spaceship.sprite.x = (SCREEN_WIDTH / 2) - SPACESHIP_WIDTH;
    spaceship.sprite.y = (SCREEN_HEIGHT - SPACESHIP_HEIGHT) - 4;
    spaceship.speed = 2;
}

void SpaceWarsUpdate(void)
{
    switch (spaceWarsGameState)
    {
    case SPACEWARS_PLAY:
        drawScreenBoundary();

        drawSprite(&spaceship.sprite);
        spaceshipMove(&spaceship);

        // drawSprite(&Jango);
        // enemyMove(&Jango);

        // drawSprite(&Jango1);
        // enemyMove(&Jango1);

        for (int i=0; i<4; i++)
        {
            drawSprite(&JangoArmy[i]);
            enemyMove(&JangoArmy[i]);
        }

        if (!bullet.active)
            spawnBullet();
        
        if (bullet.active)
        {
            drawBullet(&bullet);
            moveBullet(&bullet);
        }

        break;

    case SPACEWARS_HI_SCORE:
        break;

    default:
        break;
    }

    delay(16); // Roughly 60fps
}