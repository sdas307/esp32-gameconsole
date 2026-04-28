#include <Wire.h>
#include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include "hardware.h"
#include "display.h"
#include "input.h"
#include "assets/game icons/game_icons.h"
#include "games/PONG/Pong.h"
#include "games/SNAKE/Snake.h"
#include "games/DINO/dino.h"

int16_t selected = 0;

bool currleftPressed = false;
bool prevLeftPressed = false;

bool currrightPressed = false;
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
  GAME_DINO
};

HOVERED_APP currentHover;
APP_STATE currentState;
GAME_SELECTED currentGameSelected;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");

  #ifdef EMULATOR_BUILD
    Wire.begin(SDA, SCL);
    pinMode(JOY_SEL, INPUT_PULLUP);
  #elif defined(DEVICE_BUILD)
    Wire.begin(22, 23);
    pinMode(BUTTON_SEL, INPUT_PULLUP);
  // pinMode(21, OUTPUT);
  #endif

  initDisplay();
  showStartupScreen();

}

void loop()
{
  display.clearDisplay();

  switch (currentState)
  {
    case STATE_HOME:
      HomeManager(); // Has internal display.display()
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
  display.setTextColor(WHITE);

  display.setCursor(10, 10);
  display.print("Games");

  display.setCursor(10, 24);
  display.print("Settings");

  if (downPressed()) // DOWN button pressed
  {
    if (currentHover == HOVERED_SETTINGS)
      currentHover = HOVERED_GAMES;
    else
      currentHover = (HOVERED_APP) (currentHover + 1);
  }

  if (upPressed()) // UP button pressed
  {
    if (currentHover == HOVERED_GAMES)
      currentHover = HOVERED_SETTINGS;
    else
      currentHover = (HOVERED_APP) (currentHover - 1);
  }

  switch (currentHover)
  {
  case HOVERED_GAMES: // Games
    display.drawRect(8, 8, 33, 11, WHITE);

    if (selectPressed())
    {
      currentState = STATE_GAME;
    }
    break;

  case HOVERED_SETTINGS: // Settings
    display.drawRect(8, 22, 51, 11, WHITE);

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
    display.drawBitmap(10, 11, epd_bitmap_dino_icon, 28, 36, WHITE);
    display.drawBitmap(50, 11, epd_bitmap_pong_icon, 28, 36, WHITE);
    display.drawBitmap(90, 11, epd_bitmap_snake_icon, 28, 36, WHITE);

    currleftPressed = leftPressed();
    currrightPressed = rightPressed();

    if (currrightPressed && !prevRightPressed && selected != 2)
    {
      selected += 1;
      prevRightPressed = true;
    }
    else if (currrightPressed && !prevRightPressed)
    {
      selected = 0;
      prevRightPressed = true;
    }

    if (currleftPressed && !prevLeftPressed && selected != 0)
    {
      selected -= 1;
      prevLeftPressed = true;
    }
    else if (currleftPressed && !prevLeftPressed)
    {
      selected = 2;
      prevLeftPressed = true;
    }


    switch (selected)
    {
    case 0:
      display.drawFastHLine(16, 48, 16, WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_DINO;
      }
      break;

    case 1:
      display.drawFastHLine(55, 48, 19, WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_PONG;
      }
      break;

    case 2:
      display.drawFastHLine(93, 48, 22, WHITE);
      if (selectPressed())
      {
        notSelected = false;
        currentGameSelected = GAME_SNAKE;
      }
      break;
    
    default:
      break;
    }

    prevLeftPressed = currleftPressed;
    prevRightPressed = currrightPressed;
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