#include "gamevariables.h"
#include "hardware.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Spaceship enemy =
{
    .x = 4,
    .y = 2,
    .direction = 1,
    .speed = 2
};

void drawEnemy(const Spaceship* enemy)
{
    display.drawBitmap(enemy->x, enemy->y, bitmap_enemy, 7, 9, WHITE);
}

void enemyMove(Spaceship *enemy)
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
}