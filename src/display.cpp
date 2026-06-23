#include "display.h"
#include "hardware.h"
#include <Wire.h>
#include <Arduino.h>

void initDisplay(void)
{
    #ifdef EMULATOR_BUILD
        if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
        {
            Serial.println(F("SSD1306 allocation failed."));
            for (;;);
        }
    #elif defined(DEVICE_BUILD)
        if (!display.begin(SCREEN_ADDRESS, OLED_RESET))
        {
            Serial.println(F("SH1106 allocation failed."));
            for (;;);
        }
    #endif

    display.clearDisplay();
}

void showStartupScreen(void)
{
    display.setTextSize(1);
    display.setTextColor(DISPLAY_WHITE);
    
    display.setCursor(10, 10);
    display.println("Starting...");
    
    display.display();
    delay(100);

    display.clearDisplay();
}