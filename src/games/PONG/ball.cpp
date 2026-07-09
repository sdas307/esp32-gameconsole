#include "ball.h"
#include "hardware.h"
#include "paddle.h"
#include "gamevariables.h"
#include "input/input.h"

void drawBall(int16_t x, int16_t y, int16_t r)
{
  display.fillCircle(x, y, ballRadius, 1);
}

/* Levels are changed upon ball hit count */
void level2(void)
{
  // Cannot do ballVelX or ballVelY +=1 here
  ballVelX > 0 ?: 4, -4;
  ballVelY > 0 ?: 4, -4;
}
void level3(void)
{
  // Cannot do ballVelX or ballVelY +=1 here
  ballVelX > 0 ?: 5, -5;
  ballVelY > 0 ?: 5, -5;
}