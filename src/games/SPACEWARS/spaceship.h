#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gamevariables.h"

/**
 * Updates the spaceship's position (x values).
 * Ensures the ship statys inside the screen.
 @param ship Spaceship to update
 */
void spaceshipMove(Sprite *ship);

#endif
