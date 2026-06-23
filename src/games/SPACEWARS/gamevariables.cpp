#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

SPACE_WARS_GAME_STATE spaceWarsGameState;

float bottomPadding = SCREEN_HEIGHT - 4; // At Spaceship's y=0

Spaceship spaceship =
{
    .x = (SCREEN_WIDTH/2) - BITMAP_SPACESHIP_WIDTH,
    .y = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1,
    .speed = 2
};

// /* Spaceship Initial Position */
// float spaceshipPosX = (SCREEN_WIDTH/2) - BITMAP_SPACESHIP_WIDTH;
// float spaceshipPosY = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1;
// float spaceshipVelX = 0;
// float spaceshipMoveStrength = 2;


int16_t spaceWarsgameSpeed = 5;
unsigned long spaceWarsLastUpdate = 0;

uint16_t spaceWarsScore = 0;
char spaceWarsScoreText[10];

/* Function Definitions */

void drawSpaceship(const Spaceship* ship)
{
    display.drawBitmap(ship->x, ship->y, bitmap_spaceship, 14, 13, WHITE);
}

void spaceshipMove(Spaceship* ship)
{
    if (leftPressed())
        ship->x -= ship->speed;

    if (rightPressed())
        ship->x += ship->speed;
}

bool spaceWarsCheckCollision(void)
{
    return false;
}