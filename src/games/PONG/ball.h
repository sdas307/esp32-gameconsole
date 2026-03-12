#ifndef BALL_H
#define BALL_H

#include <stdint.h>

/* Ball Data */
extern int16_t ballX;
extern int16_t ballY;
extern int16_t ballRadius;
extern int16_t ballVelX;
extern int16_t ballVelY;

/* Collision Count */
extern int16_t hitCounter;
extern int16_t playerScore;
extern int16_t hitLevel1;
extern int16_t hitLevel2;
extern int16_t levelCount;

/* Ball Functions */
void ballObject(int16_t, int16_t, int16_t);
void level2();
void level3();

#endif