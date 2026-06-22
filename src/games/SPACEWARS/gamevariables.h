#include <stdint.h>

#define SPACESHIP_WIDTH 13
#define SPACESHIP_HEIGHT 14

/* Enum Definitions */
enum SPACE_WARS_GAME_STATE
{
    PLAY,
    HI_SCORE
};

extern SPACE_WARS_GAME_STATE spaceWarsGameState;

extern int16_t spaceWarsFrameAlt;
extern float bottomPadding;

extern float spaceshipPosX;
extern float spaceshipPosY;
extern float spaceshipVelX;
extern float jumpStrength;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/* Function Signatures */
void drawScore();
void drawGround();
void drawSpaceship();
void spaceshipMove();
bool checkCollision();