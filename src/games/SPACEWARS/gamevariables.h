#ifndef SPACEWARS_GAMEVARIABLES_H
#define SPACEWARS_GAMEVARIABLES_H

#include <stdint.h>

#define SPACESHIP_WIDTH 13
#define SPACESHIP_HEIGHT 14

/** Represents a Spaceship object. */
typedef struct
{
    /** X position of the spaceship in pixels. */
    int16_t x;

    /** Y position of the spaceship in pixels. */
    int16_t y;

    /** Horizontal movement speed in pixels per update. */
    int16_t speed;
} Spaceship;

extern Spaceship spaceship;
extern Spaceship enemy;

/* Enum Definitions */

enum SPACE_WARS_GAME_STATE
{
    PLAY,
    HI_SCORE
};

extern SPACE_WARS_GAME_STATE spaceWarsGameState;

extern float bottomPadding;

// extern float spaceshipPosX;
// extern float spaceshipPosY;
// extern float spaceshipVelX;
// extern float jumpStrength;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/* Function Signatures */

void drawScreenBoundary(void);

void enemyMove(Spaceship *enemy);
void drawEnemy(Spaceship *enemy);

/**
 * Draws the spaceship at its current position.
 @param ship Spaceship to draw
 */
void drawSpaceship(const Spaceship *ship);

/**
 * Updates the spaceship's position (x values).
 * Ensures the ship statys inside the screen.
 @param ship Spaceship to update
 */
void spaceshipMove(Spaceship *ship);

bool checkCollision(void);

#endif