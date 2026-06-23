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
    .speed = 3
};

Spaceship enemy =
{
    .x = 4,
    .y = 2,
    .speed = 2
};

int16_t spaceWarsgameSpeed = 5;
unsigned long spaceWarsLastUpdate = 0;

uint16_t spaceWarsScore = 0;
char spaceWarsScoreText[10];

void drawScreenBoundary(void)
{
    display.drawRect(0, 0, 128, 64, WHITE);
}

void drawSpaceship(const Spaceship* ship)
{
    display.drawBitmap(ship->x, ship->y, bitmap_spaceship, 14, 13, WHITE);
}

void spaceshipMove(Spaceship *ship)
{
    // If left button pressed and ship is not going outside the screen on the left
    if (leftPressed() && (ship->x >= 3))
        ship->x -= ship->speed;

    // If right button pressed and ship is not going outside the screen on the right
    if (rightPressed() && (ship->x + BITMAP_SPACESHIP_WIDTH) <= (SCREEN_WIDTH - 2))
        ship->x += ship->speed;
}

void enemyMove(Spaceship *enemy)
{
    enemy->x += enemy->speed;
}

bool spaceWarsCheckCollision(void)
{
    return false;
}