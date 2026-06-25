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
    // When no input -> ship is stationary
    ship->direction = 0;

    if (leftPressed())
    {
        ship->direction = -1;
    }

    if (rightPressed())
    {
        ship->direction = 1;
    }

    // Move ship
    ship->x += ship->speed * ship->direction;

    // Clamp to the left boundary line
    if (ship->x < 1)
    {
        ship->x = 1;
    }

    // Clamp to the right boundary line
    if (ship->x > SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH - 1)
    {
        ship->x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH - 1);
    }
}