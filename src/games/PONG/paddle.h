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
void playerPaddle(int16_t x, int16_t y, int16_t w, int16_t h);
void enemyPaddle(int16_t x, int16_t y, int16_t w, int16_t h);
void enemyAI(void);

#endif