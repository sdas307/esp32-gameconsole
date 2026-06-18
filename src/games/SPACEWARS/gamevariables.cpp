#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "../../assets/games/dino/dino_sprites.h"

SPACE_WARS_GAME_STATE spaceWarsGameState;

int16_t spaceWarsFrameAlt = 1;
float spaceWarsgroundLevel = 39; // At Dino's Y=0

/* Dino Initial Position */
float spaceshipPosX = 16;
float spaceshipPosY = 39;
float spaceshipVelY = 0;
float spaceshipJumpStrength = 8;
float spaceGravity = 1.1;

int16_t spaceWarsgameSpeed = 5;
unsigned long spaceWarsLastUpdate = 0;

uint16_t spaceWarsScore = 0;
char spaceWarsScoreText[10];

/* Function Definitions */

void drawSpace()
{
    display.drawLine(0, 57, 128, 57, WHITE);
}

void drawSpaceship()
{
    if (dinoPosY != groundLevel)
        display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino0, 16, 18, WHITE);
    else
    {
        if (spaceWarsFrameAlt == 1)
        {
            display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino1, 16, 18, WHITE);
            spaceWarsFrameAlt *= -1;
        }

        else if (spaceWarsFrameAlt == -1)
        {
            display.drawBitmap(dinoPosX, dinoPosY, bitmap_dino2, 16, 18, WHITE);
            spaceWarsFrameAlt *= -1;
        }
    }
}

void spaceshipMove()
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

void spaceWarsDrawScore()
{
    unsigned long now = millis();

    display.setCursor(3, 3);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (now - spaceWarsLastUpdate >= 100)
    {
        score++;
    }

    // Update scoreText to have a padding of 5 0's
    sprintf(scoreText, "%05d", score);

    display.print(scoreText);
}

bool spaceWarsCheckCollision()
{
    return false;
}