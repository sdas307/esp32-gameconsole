#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "cactuslogic.h"
#include "../../assets/games/dino/dino_sprites.h"

DINO_GAME_STATE dinoGameState;

int16_t dinoFrameAlt = 1;
float groundLevel = 39; // At Dino's Y=0

/*
DinoY = 39
   _
  | |
  ---
  | |
  __________________Ground (AbsoluteValue) = (DinoY + DinoHeight)
*/

/* Dino Initial Position */
float dinoPosX = 16;
float dinoPosY = 39;
float dinoVelY = 0;
float jumpStrength = 8;
float gravity = 1.1;

int16_t gameSpeed = 5;
unsigned long lastUpdate = 0;

uint16_t score = 0;
char scoreText[10];

/* Function Definitions */

void drawGround()
{
    display.drawLine(0, 57, 128, 57, WHITE);
}

void drawDino()
{
    if (dinoPosY != groundLevel)
        display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino0, 16, 18, WHITE);
    else
    {
        if (dinoFrameAlt == 1)
        {
            display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino1, 16, 18, WHITE);
            dinoFrameAlt *= -1;
        }

        else if (dinoFrameAlt == -1)
        {
            display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino2, 16, 18, WHITE);
            dinoFrameAlt *= -1;
        }
    }
}

void dinoMove()
{
    if (upPressed() && dinoPosY == groundLevel)
    {
        dinoVelY = -(jumpStrength);
    }

    if (downPressed() && dinoPosY != groundLevel)
    {
        dinoVelY = jumpStrength;
    }
    
    dinoVelY += gravity;

    dinoPosY += dinoVelY;

    /* Clamp Dino on the ground upon feet touching */
    if (dinoPosY >= groundLevel)
    {
        dinoPosY = groundLevel;
        dinoVelY = 0;
    }

}

void drawScore()
{
    unsigned long now = millis();

    display.setCursor(3, 3);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (now - lastUpdate >= 50)
    {
        score++;
        lastUpdate = now;
    }

    // Update scoreText to have a padding of 5 0's
    sprintf(scoreText, "%05d", score);

    display.print(scoreText);
}

bool checkCollision()
{
    int16_t dinoFeetX = dinoPosX + 8;
    int16_t dinoFeetY = dinoPosY + 18;
    int16_t dinoFaceX = dinoPosX + 16;
    int16_t dinoFaceY = dinoPosY;

    if (!cactusIsActive())
        return false;

    int16_t cactusX = cactusGetX();
    int16_t cactusY;
    CactusType type = cactusGetType();

    if (type == CACTUS_SMALL)
        cactusY = 43;
    else if (type == CACTUS_LARGE)
        cactusY = 40;

    if (cactusX < dinoFaceX-3-gameSpeed && cactusY < dinoFeetY-2 && !(cactusX+8 < dinoPosX))
        return true;
    else
        return false;

    // OG hand-made function -> let's not remove it?
    // if ((cactusX1 < dinoFaceX-3-gameSpeed && cactusY1 < dinoFeetY-2 && !(cactusX1+8 < dinoPosX))
    // || (cactusX2 < dinoFaceX-3-gameSpeed && cactusY2 < dinoFeetY-2 && !(cactusX2+8 < dinoPosX)))
    //     return true;
    // else
    //     return false;
}