#include <stdint.h>

/* Enum Definitions */
enum SPACE_WARS_GAME_STATE
{
    PLAY,
    HI_SCORE
};

extern SPACE_WARS_GAME_STATE spaceWarsGameState;

extern int16_t spaceWarsFrameAlt;
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
void drawScore();
void drawGround();
void drawSpaceship();
void spaceshipMove();
bool checkCollision();