#include "paddle.h"
#include "ball.h"
#include "gamevariables.h"

/* Player Paddle Data */
int16_t playerX = 2;
int16_t playerY = 24; // 64/2 - 16/2
int16_t playerWidth = 3;
int16_t playerHeight = 20;
int16_t paddleSpeed = 4;

/* Enemy Paddle Data */
int16_t enemyX = 123;
int16_t enemyY = 24;
int16_t enemyWidth = 3;
int16_t enemyHeight = 20;
// ----------------------
int16_t enemySpeed1 = 2;
int16_t enemySpeed2 = 4;
int16_t enemySpeed3 = 6;

void playerPaddle(int16_t x, int16_t y, int16_t w, int16_t h)
{
  display.fillRect(x, y, w, h, 1);
}

void enemyPaddle(int16_t x, int16_t y, int16_t w, int16_t h)
{
  display.fillRect(x, y, w, h, 1);
}

void enemyAI()
{
  /* The idea is to try to match the ball's Y coord, with the center of the paddle
   enemyY -= paddleSpeed, when the ball is in enemy court until ballY is reached...
   Three different levels, 1 -> slowly gets there, 2 -> faster, 3 -> perfect */

  if (ballX >= SCREEN_WIDTH/2)
  {
    // Ball is in enemy court

    if (ballVelY > 0)
    {
      // Ball going upwards
      if (enemyY >= 0)
        enemyPaddle(enemyX, enemyY-=enemySpeed1, enemyWidth, enemyHeight);
    }
    else
    {
      // Ball going downwards
      if (enemyY+enemyHeight <= SCREEN_HEIGHT)
        enemyPaddle(enemyX, enemyY+=enemySpeed1, enemyWidth, enemyHeight);
    }
  }
}