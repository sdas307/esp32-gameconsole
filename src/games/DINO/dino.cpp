#include <Adafruit_GFX.h>
#include "hardware.h"
#include "gamevariables.h"
#include "cactuslogic.h"
#include "mainmenu.h"
#include "hiscore.h"

int16_t cactusAlt = 1;

void DinoInit(void)
{
    score = 0;

    // dinoPosX = 16;
    // dinoPosY = 39;

    resetDino();

    // cactusSmallPosX = 128;
    // cactusSmallPosY = 43;

    // cactusLargePosX = 128;
    // cactusLargePosY = 40;

    resetCactus();
}

void DinoUpdate(void)
{

    state_change:
    if (dinoGameState == DINO_HI_SCORE)
    {
        DinoInit();
        hiScore();
    }

    if (dinoGameState == DINO_PLAY)
    {
        /* Update game-variables */
        dinoMove();
        updateCactus();

        /* Check collisions */
        if (checkCollision())
        {
            delay(1000);
            dinoGameState = DINO_HI_SCORE;

            goto state_change; // Exit out w/o drawing play screen
        }
        
        /* Draw current game state */
        drawScoreHUD();
        drawGround();
        drawCactus();
        drawDino();
    }

    /* Frame Timing - Roughly 60fps*/
    delay(16);
}