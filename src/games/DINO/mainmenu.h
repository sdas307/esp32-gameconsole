#ifndef DINO_MAINMENU_H
#define DINO_MAINMENU_H

#include <stdint.h>

#define DINO_DEBOUNCE_DELAY 500
extern int16_t dinoAlt;
extern unsigned long dinoLastDebounceTime;

void dinoMainMenu(void);

#endif