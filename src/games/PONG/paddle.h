#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <stdint.h>

/* Player Paddle Data */
extern int16_t playerX;
extern int16_t playerY;
extern int16_t playerWidth;
extern int16_t playerHeight;
extern int16_t paddleSpeed;

/* Enemy Paddle Data */
extern int16_t enemyX;
extern int16_t enemyY;
extern int16_t enemyWidth;
extern int16_t enemyHeight;
// ----------------------
extern int16_t enemySpeed1;
extern int16_t enemySpeed2;
extern int16_t enemySpeed3;

/* Paddle Functions */

/* Ball Functions */

/** Draw Player Paddle on screen.
 * @param x  X Co-ordinate
 * @param y  Y Co-ordinate
 * @param w  Width
 * @param h  Height
 */
void drawPlayerPaddle(int16_t x, int16_t y, int16_t w, int16_t h);

/** Draw Enemy Paddle on screen.
 * @param x  X Co-ordinate
 * @param y  Y Co-ordinate
 * @param w  Width
 * @param h  Height
 */
void drawEnemyPaddle(int16_t x, int16_t y, int16_t w, int16_t h);

/** Draw enemy paddle at its current position. */
//void drawEnemyPaddle(void);

/** Compute enemy paddle position based on ball's y-movement. */
void enemyAI(void);

#endif