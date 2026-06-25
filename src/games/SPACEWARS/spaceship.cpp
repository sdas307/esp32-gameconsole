#include "gamevariables.h"
#include "hardware.h"
#include "input/input.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Spaceship spaceship =
{
    .x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH) / 2,
    .y = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1,
    .speed = 3
};

void drawSpaceship(const Spaceship* ship)
{
    display.drawBitmap(ship->x, ship->y, bitmap_spaceship, 13, 13, WHITE);
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