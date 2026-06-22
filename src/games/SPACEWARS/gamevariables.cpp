#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "../../assets/games/spacewars/space_wars_sprites.h"

SPACE_WARS_GAME_STATE spaceWarsGameState;

int16_t spaceWarsFrameAlt = 1;
float bottomPadding = SCREEN_HEIGHT - 4; // At Spaceship's y=0

/* Spaceship Initial Position */
float spaceshipPosX = 12;
float spaceshipPosY = 26;
float spaceshipVelY = 0;
float spaceshipMoveStrength = 8;
// float spaceGravity = 1.1;

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
    if (spaceshipPosY != bottomPadding)
        display.drawBitmap(spaceshipPosX, spaceshipPosY, bitmap_spaceship0, 16, 18, WHITE);
    else
    {
        if (spaceWarsFrameAlt == 1)
        {
            display.drawBitmap(spaceshipPosX, spaceshipPosY, bitmap_spaceship1, 16, 18, WHITE);
            spaceWarsFrameAlt *= -1;
        }

        else if (spaceWarsFrameAlt == -1)
        {
            display.drawBitmap(spaceshipPosX, spaceshipPosY, bitmap_spaceship1, 16, 18, WHITE);
            spaceWarsFrameAlt *= -1;
        }
    }
}

void spaceshipMove()
{
    if (upPressed())
    {
        spaceshipVelY = -(spaceshipMoveStrength);
    }

    if (downPressed())
    {
        spaceshipVelY = spaceshipMoveStrength;
    }
    
    // spaceshipVelY += spaceGravity;

    spaceshipPosY += spaceshipVelY;

    // /* Clamp Spaceship on the ground upon feet touching */
    // if (spaceshipPosY >= bottomPadding)
    // {
    //     spaceshipPosY = bottomPadding;
    //     spaceshipVelY = 0;
    // }

}

void spaceWarsDrawScore()
{
    unsigned long now = millis();

    display.setCursor(3, 3);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (now - spaceWarsLastUpdate >= 100)
    {
        spaceWarsScore++;
    }

    // Update scoreText to have a padding of 5 0's
    sprintf(spaceWarsScoreText, "%05d", spaceWarsScore);

    display.print(spaceWarsScoreText);
}

bool spaceWarsCheckCollision()
{
    return false;
}