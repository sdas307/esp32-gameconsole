#ifndef DINO_GAMEVARIABLES_H
#define DINO_GAMEVARIABLES_H

#include <stdint.h>

#define MAX_DINO_JUMP_HEIGHT 10

/* Enum Definitions */
enum DINO_GAME_STATE
{
    PLAY,
    HI_SCORE
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

void spawnDino(void);

void drawScore(void);
void drawGround(void);
void drawDino(void);
void dinoMove(void);
bool checkCollision(void);

#endif