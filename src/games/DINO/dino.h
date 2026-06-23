#ifndef DINO_H
#define DINO_H

/**
 * Initialize Dino.
 * Set game variables to default values.
 */
void DinoInit(void);

/**
 * Update game variables (frame by frame when called from main.cpp's GameManager()).
 * DinoUpdate does not use display.display() internally.
 */
void DinoUpdate(void);

#endif