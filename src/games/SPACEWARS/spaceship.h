#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gamevariables.h"

typedef struct Spaceship
{
    Sprite sprite;

    int8_t hp;

    int16_t speed;

    bool active;

} Spaceship;

extern Spaceship spaceship;

/**
 * Updates the spaceship's position (x values).
 * Ensures the ship statys inside the screen.
 @param ship Spaceship to update
 */
void spaceshipMove(Spaceship *ship);

#endif
