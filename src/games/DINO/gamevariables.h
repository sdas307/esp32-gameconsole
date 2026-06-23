#ifndef DINO_GAMEVARIABLES_H
#define DINO_GAMEVARIABLES_H

#include <stdint.h>

#define MAX_DINO_JUMP_HEIGHT 10

/* Enum Definitions */

/** Possible game states for Dino. */
enum DINO_GAME_STATE
{
    /** Active gameplay. */
    DINO_PLAY,

    /** High score screen. */
    DINO_HI_SCORE
};

extern DINO_GAME_STATE dinoGameState;

extern int16_t dinoFrameAlt;
extern float groundLevel;

extern float dinoPosX;
extern float dinoPosY;
extern float dinoVelY;
extern float jumpStrength;
extern float gravity;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/* Function Signatures */

/** Reset Dino game variables. */
void resetDino(void);

/** Draw score at the top left corner of the game screen. */
void drawScoreHUD(void);

/** Draw a straight line representing ground. */
void drawGround(void);

/** Draw Dino at its current position. */
void drawDino(void);

/** Update Dino position based on user input. */
void dinoMove(void);

/** Returns true on collision with cactus, or ground. */
bool checkCollision(void);

#endif