#include <stdint.h>
#include "hardware.h"
#include "input/input.h"
#include "gamevariables.h"

void highScore(void)
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

  if (leftPressed()) // LEFT is pressed
  {
    // Restart game from main menu
    pongGameState = PONG_MAIN_MENU;
  }
  else if (rightPressed()) // RIGHT is pressed
  {
    // For now, still go back to main menu
    pongGameState = PONG_MAIN_MENU;
  }
}