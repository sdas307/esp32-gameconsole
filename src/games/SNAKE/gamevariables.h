#ifndef SNAKE_GAMEVARIABLES_H
#define SNAKE_GAMEVARIABLES_H

#include <stdint.h>

#define SNAKE_WIDTH 8
#define SNAKE_HEIGHT 4
#define SNAKE_MAX_LENGTH 100

/* Strucs and Enums*/

/** Body of the snake. */
struct Segment
{
    int16_t x;
    int16_t y;
};

/** Possible game states of Snake. */
enum GAME_STATE
{
    /** Main menu screen. */
    SNAKE_MAIN_MENU,

    /** Gameplay screen. */
    SNAKE_PLAY,

    /** High score screen. */
    SNAKE_HI_SCORE
};

/** Possible directions to move in for the snake. */
enum DIRECTION
{
    LEFT, RIGHT,
    UP, DOWN
};

/** Possible sides of the body the snake can collide with. */
enum COLLISION
{
    COLLIDE_NONE,
    COLLIDE_LEFT, COLLIDE_RIGHT,
    COLLIDE_TOP, COLLIDE_BOTTOM
};

/* External Variables */

extern GAME_STATE gameState;
extern unsigned long snakeLastDebounceTime;
extern int16_t snakeAlt;

// Snake Information

extern int16_t SEGMENT_SIZE;
extern int16_t SEGMENT_RADIUS;
extern int16_t snakeLength;
extern Segment snake[SNAKE_MAX_LENGTH];
extern DIRECTION direction;
extern COLLISION collision;

// Snake Score

extern int16_t snakeScore;

// Food Information

extern int16_t foodRadius;
extern int16_t foodX;
extern int16_t foodY;
extern bool toGenerate;
extern bool foodEaten;

// Useful Variables

extern bool gameReset;
extern bool prevSelectState;

/** Timestamp (in milliseconds) of the snake's most recent movement. */
extern unsigned long lastMove;

/** Time intervals (in milliseconds) between snake movements. */
extern const unsigned long moveInterval;

#endif