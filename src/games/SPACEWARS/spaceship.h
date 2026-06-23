#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gamevariables.h"

/**
 * Draws the spaceship at its current position.
 @param ship Spaceship to draw
 */
void drawSpaceship(const Spaceship* ship);

/**
 * Updates the spaceship's position (x values).
 * Ensures the ship statys inside the screen.
 @param ship Spaceship to update
 */
void spaceshipMove(Spaceship *ship);

#endif
