#include "gamevariables.h"
#include "hardware.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

Spaceship enemy =
{
    .x = 4,
    .y = 2,
    .speed = 2
};

void drawEnemy(const Spaceship* enemy)
{
    display.drawBitmap(enemy->x, enemy->y, bitmap_spaceship, 14, 13, WHITE);
}

void enemyMove(Spaceship *enemy)
{
    enemy->x += enemy->speed;
}