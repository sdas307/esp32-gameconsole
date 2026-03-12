#include <stdint.h>

#define SNAKE_WIDTH 8
#define SNAKE_HEIGHT 4
#define SNAKE_MAX_LENGTH 100

/* Strucs and Enums*/
struct Segment
{
    int16_t x;
    int16_t y;
};

enum GAME_STATE
{
    MAIN_MENU,
    PLAY, HI_SCORE
};

enum DIRECTION
{
    LEFT, RIGHT,
    UP, DOWN
};

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

extern unsigned long lastMove;
extern const unsigned long moveInterval;