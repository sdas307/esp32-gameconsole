#include "gamevariables.h"
#include "hardware.h"
#include "input/input.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Sprite Spaceship =
{
    .sprites = bitmap_SpaceshipSprites,
    .spriteCount = bitmap_SpaceshipSprites_LEN,
    .spriteIndex = 0,
    .lastFrameTime = 0,
    .width = 13,
    .height = 13,
    .x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH) / 2,
    .y = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1,
    .speed = 3
};

void spaceshipMove(Sprite *ship)
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