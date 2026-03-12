#ifndef GAMEVARIABLES_H
#define GAMEVARIABLES_H

#include <stdint.h>
#include "hardware.h"

/* Structs and Enums*/
enum PONG_GAME_STATE
{
    PONG_MAIN_MENU,
    PONG_PLAY,
    PONG_HI_SCORE
};

/* Game variables*/
extern PONG_GAME_STATE pongGameState;
extern bool toDelay;
extern int16_t pongAlt;

/* Button variables*/
#define DEBOUNCE_DELAY 500  // 500ms debounce time
extern unsigned long lastDebounceTime;

/* Game Functions*/
void dividerLines();

#endif