#ifndef SPACEWARS_MAIN_MENU_H
#define SPACEWARS_MAIN_MENU_H

#include <stdint.h>

#define DINO_DEBOUNCE_DELAY 500
extern int16_t spaceWarsAlt;
extern unsigned long spaceWarsLastDebounceTime;

void spaceWarsMainMenu(void);

#endif