#ifndef SNAKE_MAINMENU_H
#define SNAKE_MAINMENU_H

#include <stdint.h>

#define SNAKE_DEBOUNCE_DELAY 500
extern int16_t snakeAlt;
extern unsigned long snakeLastDebounceTime;

void snakeMainMenu();

#endif