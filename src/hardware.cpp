#include "hardware.h"
#include <Wire.h>

#ifdef EMULATOR_BUILD
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#elif defined(DEVICE_BUILD)
    Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#endif