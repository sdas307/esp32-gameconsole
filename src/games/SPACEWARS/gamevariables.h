#ifndef SPACEWARS_GAMEVARIABLES_H
#define SPACEWARS_GAMEVARIABLES_H

#include <stdint.h>

#define SPACESHIP_WIDTH 13
#define SPACESHIP_HEIGHT 14

/** Represents a Spaceship. */
typedef struct
{
    /** X position of the spaceship in pixels. */
    int16_t x;

    /** Y position of the spaceship in pixels. */
    int16_t y;

    /** Horizontal movement direction
     * (-1 = left, 1 = right). */
    int8_t direction;

    /** Horizontal movement speed in pixels per update. */
    int16_t speed;
} Spaceship;

extern Spaceship spaceship;
extern Spaceship enemy;

/* Enum Definitions */

/** Possible game states for Space Wars. */
enum SPACEWARS_GAME_STATE
{
    /** Gameplay screen. */
    SPACEWARS_PLAY,

    /** High score screen. */
    SPACEWARS_HI_SCORE
};

extern SPACEWARS_GAME_STATE spaceWarsGameState;

extern float bottomPadding;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/**
 * Draw screen boundary (Rectangle - Screen Width x Screen Height).
 */
void drawScreenBoundary(void);

bool checkCollision(void);

#endif