#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include "hardware.h"
#include "inputs.h"
#include "assets/game icons/game_icons.h"
#include "games/PONG/Pong.h"
#include "games/SNAKE/Snake.h"
#include "games/DINO/dino.h"

int16_t selected = 0;

bool leftPressed = false;
bool prevLeftPressed = false;

bool rightPressed = false;
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

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");

  Wire.begin(22, 23);
  pinMode(JOY_SEL, INPUT_PULLUP);
  // pinMode(21, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("Starting...");
  display.display();
  delay(100);
  display.clearDisplay();
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

  if (BUTTON_DOWN()) // DOWN button pressed
  {
    if (currentHover == HOVERED_SETTINGS)
      currentHover = HOVERED_GAMES;
    else
      currentHover = (HOVERED_APP) (currentHover + 1);
  }

  if (BUTTON_UP()) // UP button pressed
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

    if (BUTTON_SELECT())
    {
      currentState = STATE_GAME;
    }
    break;

  case HOVERED_SETTINGS: // Settings
    display.drawRect(8, 22, 51, 11, WHITE);

    if (BUTTON_SELECT())
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

    leftPressed = BUTTON_LEFT();
    rightPressed = BUTTON_RIGHT();

    if (rightPressed && !prevRightPressed && selected != 2)
    {
      selected += 1;
      prevRightPressed = true;
    }
    else if (rightPressed && !prevRightPressed)
    {
      selected = 0;
      prevRightPressed = true;
    }

    if (leftPressed && !prevLeftPressed && selected != 0)
    {
      selected -= 1;
      prevLeftPressed = true;
    }
    else if (leftPressed && !prevLeftPressed)
    {
      selected = 2;
      prevLeftPressed = true;
    }


    switch (selected)
    {
    case 0:
      display.drawFastHLine(16, 48, 16, WHITE);
      if (BUTTON_SELECT())
      {
        notSelected = false;
        currentGameSelected = GAME_DINO;
      }
      break;

    case 1:
      display.drawFastHLine(55, 48, 19, WHITE);
      if (BUTTON_SELECT())
      {
        notSelected = false;
        currentGameSelected = GAME_PONG;
      }
      break;

    case 2:
      display.drawFastHLine(93, 48, 22, WHITE);
      if (BUTTON_SELECT())
      {
        notSelected = false;
        currentGameSelected = GAME_SNAKE;
      }
      break;
    
    default:
      break;
    }

    prevLeftPressed = leftPressed;
    prevRightPressed = rightPressed;
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

  if (BUTTON_LEFT() || BUTTON_RIGHT())
  {
    // Press LEFT or RIGHT to go back to homescreen
    currentState = STATE_HOME;
  }
}