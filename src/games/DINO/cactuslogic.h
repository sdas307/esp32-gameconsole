#ifndef DINO_CACTUSLOGIC_H
#define DINO_CACTUSLOGIC_H

#include <stdint.h>

/* Enums */

/**
 * Stores Cactus Type.
 */
typedef enum
{
    /** 'cactus_small', 8x14 */
    CACTUS_SMALL = 0,

    /** 'cactus_large', 8x17 */
    CACTUS_LARGE = 1
} CactusType;

/* External Variables */
extern const int16_t cactusSmallPosY;
extern const int16_t cactusLargePosY;

/* Function Signatures */

// void drawCactusSmall(const Cactus *cactus);
// void drawCactusLarge(const Cactus *cactus);

/** Updates the cactus at its current position. */
void updateCactus(void);

/** Generates random values to determine the cactus type (SMALL or LARGE). */
CactusType randomCactusType(void);

/** Spawns a new cactus. */
void drawCactus(void);
void resetCactus(void);

/* Getter Functions */
bool cactusIsActive();
int16_t cactusGetX();
CactusType cactusGetType();

#endif