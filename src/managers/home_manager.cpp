#include "hardware.h"
#include "input/input.h"
#include "manager.h"

void HomeManager(void)
{
  display.setTextSize(1);
  display.setTextColor(DISPLAY_WHITE);

  display.setCursor(10, 10);
  display.print("Games");

  display.setCursor(10, 24);
  display.print("Settings");

  if (downPressed()) // DOWN button pressed
  {
    if (currentHover == HOVERED_SETTINGS)
      currentHover = HOVERED_GAMES;
    else
      currentHover = (HOVERED_APP)(currentHover + 1);
  }

  if (upPressed()) // UP button pressed
  {
    if (currentHover == HOVERED_GAMES)
      currentHover = HOVERED_SETTINGS;
    else
      currentHover = (HOVERED_APP)(currentHover - 1);
  }

  switch (currentHover)
  {
  case HOVERED_GAMES: // Games
    display.drawRect(8, 8, 33, 11, DISPLAY_WHITE);

    if (selectPressed())
    {
      currentState = STATE_GAME;
    }
    break;

  case HOVERED_SETTINGS: // Settings
    display.drawRect(8, 22, 51, 11, DISPLAY_WHITE);

    if (selectPressed())
    {
      currentState = STATE_SETTINGS;
    }
    break;

  default:
    break;
  }
  delay(100); // Debounce needs work here ######
}