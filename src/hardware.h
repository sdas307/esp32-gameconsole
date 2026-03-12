#ifndef HARDWARE_H
#define HARDWARE_H

#include <Adafruit_SSD1306.h>

// OLED Definition
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET    -1  
#define SCREEN_ADDRESS 0x3C  // For THIS model of the display

// Joystick Definition
#define JOY_X 2
#define JOY_Y 15
#define JOY_SEL 4

extern Adafruit_SSD1306 display;

#endif