#include "hardware.h"
#include "input/input.h"
#include "manager.h"
#include "assets/game icons/game_icons.h"
#include "games/PONG/Pong.h"
#include "games/SNAKE/Snake.h"
#include "games/DINO/dino.h"
#include "games/SPACEWARS/spacewars.h"

int16_t selected = 0;

bool notSelected = true;

bool currLeftPressed = false;
bool prevLeftPressed = false;
bool upOrDownPressed = false;

bool currRightPressed = false;
bool prevRightPressed = false;

void GameManager(void)
{
  if (notSelected)
  {
    // Show Game Icons
    display.drawBitmap(10, 11, bitmap_games_icon[0], 28, 36, DISPLAY_WHITE);
    display.drawBitmap(50, 11, bitmap_games_icon[1], 28, 36, DISPLAY_WHITE);
    display.drawBitmap(90, 11, bitmap_games_icon[2], 28, 36, DISPLAY_WHITE);
    display.drawBitmap(1, 18, bitmap_left_slider_arrow, 7, 14, DISPLAY_WHITE);
    display.drawBitmap(SCREEN_WIDTH - 1 - 7, 18, bitmap_right_slider_arrow, 7, 14, DISPLAY_WHITE);

    currLeftPressed = leftPressed();
    currRightPressed = rightPressed();

    if (currRightPressed && !prevRightPressed && selected != 3)
    {
      selected += 1;
      prevRightPressed = true;
    }
    else if (currRightPressed && !prevRightPressed)
    {
      selected = 0;
      prevRightPressed = true;
    }

    if (currLeftPressed && !prevLeftPressed && selected != 0)
    {
      selected -= 1;
      prevLeftPressed = true;
    }
    else if (currLeftPressed && !prevLeftPressed)
    {
      selected = 3;
      prevLeftPressed = true;
    }

    if (selected == 3)
    {
      display.clearDisplay();
      display.drawBitmap(10, 11, bitmap_space_wars_icon, 28, 36, DISPLAY_WHITE);
      display.drawBitmap(1, 18, bitmap_left_slider_arrow, 7, 14, DISPLAY_WHITE);
    }

    // Draw a line under selected game name
    switch (selected)
    {
    case 0:
      display.drawFastHLine(16, 48, 16, DISPLAY_WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_DINO;
      }
      break;

    case 1:
      display.drawFastHLine(55, 48, 19, DISPLAY_WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_PONG;
      }
      break;

    case 2:
      display.drawFastHLine(93, 48, 22, DISPLAY_WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_SNAKE;
      }
      break;

    case 3:
      display.drawFastHLine(13, 48, 22, DISPLAY_WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_SPACE_WARS;
      }
      break;

    default:
      break;
    }

    prevLeftPressed = currLeftPressed;
    prevRightPressed = currRightPressed;
  }

  if (currentGameSelected == GAME_PONG)
  {
    PongUpdate();
  }
  else if (currentGameSelected == GAME_SNAKE)
  {
    SnakeUpdate();
  }
  else if (currentGameSelected == GAME_DINO)
  {
    DinoUpdate();
  }
  else if (currentGameSelected == GAME_SPACE_WARS)
  {
    SpaceWarsUpdate();
  }
}