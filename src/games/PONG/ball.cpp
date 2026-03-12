#include "ball.h"
#include "hardware.h"
#include "paddle.h"
#include "gamevariables.h"
#include "inputs.h"

void ballObject(int16_t x, int16_t y, int16_t r)
{
  display.fillCircle(x, y, ballRadius, 1);
}

/* Levels are changed upon ball hit count */
void level2()
{
  // Cannot do ballVelX or ballVelY +=1 here
  ballVelX > 0 ?: 4, -4;
  ballVelY > 0 ?: 4, -4;
}
void level3()
{
  // Cannot do ballVelX or ballVelY +=1 here
  ballVelX > 0 ?: 5, -5;
  ballVelY > 0 ?: 5, -5;
}

void highScore()
{
  display.setTextSize(1);
  display.setCursor(10, 10);

  display.print("Your Score:");
  display.setCursor(10, 20);
  display.print(playerScore);

  display.setCursor(10, 30);
  display.print("LEFT --> Restart");

  display.setCursor(10, 40);
  display.print("RIGHT --> Exit");

  if (BUTTON_LEFT()) // LEFT is pressed
  {
    // Restart game from main menu
    pongGameState = PONG_MAIN_MENU;
  }
  else if (BUTTON_RIGHT()) // RIGHT is pressed
  {
    // For now, still go back to main menu
    pongGameState = PONG_MAIN_MENU;
  }
}