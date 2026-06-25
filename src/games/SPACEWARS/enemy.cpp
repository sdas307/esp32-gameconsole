#include "gamevariables.h"
#include "hardware.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Sprite Enemy =
{
    .sprites = bitmap_EnemySprites,
    .spriteCount = bitmap_EnemySprites_LEN,
    .spriteIndex = 0,
    .lastFrameTime = 0,
    .width = 7,
    .height = 9,
    .x = 4,
    .y = 2,
    .direction = 1,
    .speed = 2
};

Sprite Jango =
{
    .sprites = bitmap_JangoSprites,
    .spriteCount = bitmap_JangoSprites_LEN,
    .spriteIndex = 0,
    .lastFrameTime = 0,
    .width = 9,
    .height = 7,
    .x = 4,
    .y = 2,
    .direction = 1,
    .speed = 2
};

void enemyMove(Sprite *enemy)
{
    // Enemy touches right boundary line
    if ((enemy->x + BITMAP_ENEMY_WIDTH) >= (SCREEN_WIDTH - 1))
    {
        enemy->direction = -1;
    }

    // Enemy touches left boundary line
    if (enemy->x <= 1)
    {
        enemy->direction = 1;
    }

    enemy->x += enemy->speed * enemy->direction;

    spriteUpdate(enemy, 100);
}