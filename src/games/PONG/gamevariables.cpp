#include "gamevariables.h"
#include "input.h"

/* Ball Data */
int16_t ballX = 62; // 128/2 - radius
int16_t ballY = 30; // Width/2 - radius
int16_t ballRadius = 2;
int16_t ballVelX = 3;
int16_t ballVelY = 3;

/* Collision Count*/
int16_t hitCounter = 0;
int16_t playerScore = 0;
int16_t hitLevel1 = 2;
int16_t hitLevel2 = 4;
int16_t levelCount = 1;

/* Game variables*/
PONG_GAME_STATE pongGameState;
bool toDelay = true;
int16_t pongAlt = 1;

/* Button variables*/
unsigned long lastDebounceTime = 0;

void dividerLines(void)
{
  for (int y=0; y<=SCREEN_HEIGHT; y+=2)
  {
    display.drawPixel(SCREEN_WIDTH/2 - 1, y, 1);
    display.drawPixel(SCREEN_WIDTH/2 + 1, y, 1);
  }
}