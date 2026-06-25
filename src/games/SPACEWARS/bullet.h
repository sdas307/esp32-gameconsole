#ifndef BULLET_H
#define BULLET_H

#include <stdint.h>

typedef struct Bullet
{
    int16_t x;

    int16_t y;

    int8_t speed;

    bool active;
    
} Bullet;

extern Bullet bullet;

void spawnBullet(void);

void drawBullet(Bullet *bullet);

void moveBullet(Bullet *bullet);

#endif