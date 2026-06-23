#ifndef ENEMY_H
#define ENEMY_H

#include "gamevariables.h"

/**
 * Draws enemy at its current position.
 @param enemy Enemy to draw
 */
void drawEnemy(const Spaceship *enemy);

/**
 * Update enemy position (x value).
 * Ensures enemy statys inside the screen.
 @param enemy Enemy to update
 */
void enemyMove(Spaceship *enemy);

#endif