#ifndef PONG_BALL_H
#define PONG_BALL_H

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

/** Draw ball on screen.
 * @param x  X Co-ordinate
 * @param y  Y Co-ordinate
 * @param r  Radius
 */
void drawBall(int16_t x, int16_t y, int16_t r);


void level2(void);
void level3(void);

#endif