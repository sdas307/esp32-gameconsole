#ifndef ENEMY_H
#define ENEMY_H

#include "gamevariables.h"

/**
 * Update enemy position (x value).
 * Ensures enemy statys inside the screen.
 @param enemy Enemy to update
 */
void enemyMove(Sprite *enemy);

#endif