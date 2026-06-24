#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>
#include "hardware.h"
#include "display.h"
#include "input.h"
#include "manager.h"
#include "home_manager.h"
#include "game_manager.h"
#include "settings_manager.h"
#include "assets/game icons/game_icons.h"

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