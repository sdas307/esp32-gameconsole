#include "game_console.h"

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
        HomeManager();
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