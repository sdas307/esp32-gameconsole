#include "spaceship.h"
#include "hardware.h"
#include "input/input.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Spaceship spaceship =
{
    .sprite =
    {
        .sprites = bitmap_SpaceshipSprites,
        .spriteCount = bitmap_SpaceshipSprites_LEN,
        .spriteIndex = 0,
        .lastFrameTime = 0,
        .width = 13,
        .height = 13,
        .x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH) / 2,
        .y = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1
    },
    .speed = 2
};

// Sprite Spaceship =
// {
//     .sprites = bitmap_SpaceshipSprites,
//     .spriteCount = bitmap_SpaceshipSprites_LEN,
//     .spriteIndex = 0,
//     .lastFrameTime = 0,
//     .width = 13,
//     .height = 13,
//     .x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH) / 2,
//     .y = (SCREEN_HEIGHT - BITMAP_SPACESHIP_HEIGHT) - 1,
//     .speed = 3
// };

void spaceshipMove(Spaceship *ship)
{
    // When no input -> ship is stationary
    ship->sprite.direction = 0;

    if (leftPressed())
    {
        ship->sprite.direction = -1;
    }

    if (rightPressed())
    {
        ship->sprite.direction = 1;
    }

    // Move ship
    ship->sprite.x += ship->speed * ship->sprite.direction;

    // Clamp to the left boundary line
    if (ship->sprite.x < 1)
    {
        ship->sprite.x = 1;
    }

    // Clamp to the right boundary line
    if (ship->sprite.x > SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH - 1)
    {
        ship->sprite.x = (SCREEN_WIDTH - BITMAP_SPACESHIP_WIDTH - 1);
    }
}