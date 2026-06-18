#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>
#include "hardware.h"
#include "display.h"
#include "input.h"
#include "assets/game icons/game_icons.h"
#include "games/PONG/Pong.h"
#include "games/SNAKE/Snake.h"
#include "games/DINO/dino.h"
#include "games/SPACEWARS/spacewars.h"

int16_t selected = 0;

bool currLeftPressed = false;
bool prevLeftPressed = false;
bool upOrDownPressed = false;

bool currRightPressed = false;
bool prevRightPressed = false;

bool notSelected = true;
void HomeManager();
void GameManager();
void SettingsManager();

enum HOVERED_APP
{
  HOVERED_GAMES,
  HOVERED_SETTINGS
};

enum APP_STATE
{
  STATE_HOME,
  STATE_GAME,
  STATE_SETTINGS
};

enum GAME_SELECTED
{
  GAME_NONE,
  GAME_PONG,
  GAME_SNAKE,
  GAME_DINO,
  GAME_SPACE_WARS
};

HOVERED_APP currentHover;
APP_STATE currentState;
GAME_SELECTED currentGameSelected;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");

  initHardware();
  initDisplay();
  showStartupScreen();
}

void loop()
{
  display.clearDisplay();

  switch (currentState)
  {
  case STATE_HOME:
    HomeManager(); // Has internal display.display()??
    break;

  case STATE_GAME:
    GameManager();
    break;

  case STATE_SETTINGS:
    SettingsManager();
    break;

  default:
    break;
  }

  display.display();
}

void HomeManager()
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

void GameManager()
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

void SettingsManager()
{
  display.setCursor(10, 32);
  display.print("Work in Progress!");
  display.setCursor(10, 42);
  display.print("<-- Go Back -->");
  display.display();

  if (leftPressed() || rightPressed())
  {
    // Press LEFT or RIGHT to go back to homescreen
    currentState = STATE_HOME;
  }
}