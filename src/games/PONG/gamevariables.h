#ifndef PONG_GAMEVARIABLES_H
#define PONG_GAMEVARIABLES_H

#include <stdint.h>
#include "hardware.h"

/* Structs and Enums*/

/** Possible game states for Pong. */
enum PONG_GAME_STATE
{
    /** Main menu screen. */
    PONG_MAIN_MENU,

    /** Active gameplay. */
    PONG_PLAY,

    /** High score screen. */
    PONG_HI_SCORE
};

/* Game variables*/

extern PONG_GAME_STATE pongGameState;
extern int16_t playerScore;
extern bool toDelay;
extern int16_t pongAlt;

/* Button variables*/

#define DEBOUNCE_DELAY 500  // 500ms debounce time
extern unsigned long lastDebounceTime;

/* Game Functions*/

void dividerLines(void);

#endif