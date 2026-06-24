#include "hardware.h"
#include "input/input.h"
#include "manager.h"

void SettingsManager(void)
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