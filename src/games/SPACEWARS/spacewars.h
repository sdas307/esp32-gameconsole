#ifndef SPACEWARS_H
#define SPACEWARS_H

/**
 * Initialize Space Wars.
 * Set game variables to default values.
 */
void SpaceWarsInit(void);

/**
 * Update game variables (frame by frame when called from main.cpp's GameManager()).
 * SpaceWarsUpdate does not use display.display() internally.
 */
void SpaceWarsUpdate(void);

#endif