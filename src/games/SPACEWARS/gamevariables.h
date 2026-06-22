#ifndef GAMEVARIABLES_H
#define GAMEVARIABLES_H

#include <stdint.h>

#define SPACESHIP_WIDTH 13
#define SPACESHIP_HEIGHT 14

typedef struct
{
    int16_t x;
    int16_t y;
    int16_t speed;
} Spaceship;

extern Spaceship spaceship;

/* Enum Definitions */
enum SPACE_WARS_GAME_STATE
{
    PLAY,
    HI_SCORE
};

extern SPACE_WARS_GAME_STATE spaceWarsGameState;

extern int16_t spaceWarsFrameAlt;
extern float bottomPadding;

// extern float spaceshipPosX;
// extern float spaceshipPosY;
// extern float spaceshipVelX;
// extern float jumpStrength;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/* Function Signatures */
void drawScore();
void drawGround();
void drawSpaceship(const Spaceship* ship);
void spaceshipMove(Spaceship* );
bool checkCollision();

#endif