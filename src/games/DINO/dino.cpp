#include <Adafruit_GFX.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "cactuslogic.h"
#include "mainmenu.h"
#include "hiscore.h"

int16_t cactusAlt = 1;

void DinoInit()
{
    score = 0;

    dinoPosX = 16;
    dinoPosY = 39;

    // cactusSmallPosX = 128;
    // cactusSmallPosY = 43;

    // cactusLargePosX = 128;
    // cactusLargePosY = 40;

    resetCactus();
}

void DinoUpdate()
{

    state_change:
    if (dinoGameState == HI_SCORE)
    {
        DinoInit();
        hiScore();
    }

    if (dinoGameState == PLAY)
    {
        /* Update game-variables */
        dinoMove();
        updateCactus();

        /* Check collisions */
        if (checkCollision())
        {
            delay(1000);
            dinoGameState = HI_SCORE;

            goto state_change; // Exit out w/o drawing play screen
        }
        
        /* Draw current game state */
        drawScore();
        drawGround();
        drawCactus();
        drawDino();
    }

    /* Frame Timing - Roughly 60fps*/
    delay(16);
}