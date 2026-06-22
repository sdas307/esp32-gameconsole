#ifndef DINO_CACTUSLOGIC_H
#define DINO_CACTUSLOGIC_H

#include <stdint.h>

/* Enums */
typedef enum
{
    CACTUS_SMALL = 0,
    CACTUS_LARGE = 1
} CactusType;

/* External Variables */
extern int16_t cactusSmallPosY;
extern int16_t cactusLargePosY;

/* Function Signatures */
void drawCactusSmall(int16_t cactusX);
void drawCactusLarge(int16_t cactusX);
void updateCactus();
void spawnCactus();
void drawCactus();
void resetCactus();

/* Getter Functions */
bool cactusIsActive();
int16_t cactusGetX();
CactusType cactusGetType();

#endif