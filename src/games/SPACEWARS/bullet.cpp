#include "bullet.h"
#include "spaceship.h"
#include "gamevariables.h"
#include "hardware.h"

Bullet bullet = {.active = false};

void spawnBullet(void)
{
    bullet.x = (spaceship.sprite.x + (spaceship.sprite.width/2));
    bullet.y = spaceship.sprite.y;
    bullet.speed = 3;
    bullet.active = true;
}

void drawBullet(Bullet *bullet)
{
    display.fillRect(bullet->x, bullet->y, 1, 2, WHITE);
}

void moveBullet(Bullet *bullet)
{
    bullet->y -= bullet->speed;

    if (bullet->y <= 0)
        bullet->active = false;
}