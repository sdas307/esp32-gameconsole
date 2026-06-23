#include "hardware.h"
#include <Wire.h>

// ===== Display initialization =====
#ifdef EMULATOR_BUILD
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#elif defined(DEVICE_BUILD)
    Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#endif

// ===== Hardware initialization =====
void initHardware(void)
{
    // I2C init (same for both now)
    Wire.begin(SDA, SCL);

    // Input setup
    #ifdef EMULATOR_BUILD
        pinMode(JOY_SEL, INPUT_PULLUP);
    #elif defined(DEVICE_BUILD)
        pinMode(BUTTON_SEL, INPUT_PULLUP);
    #endif

        // Buzzer (only exists on device)
    #ifdef DEVICE_BUILD
        pinMode(BUZZER, OUTPUT);
    #endif
}