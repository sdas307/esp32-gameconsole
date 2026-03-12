#include <stdint.h>
#include "gamevariables.h"

GAME_STATE gameState;
unsigned long snakeLastDebounceTime = 0;
int16_t snakeAlt = 1;

int16_t SEGMENT_SIZE = 6;
int16_t SEGMENT_RADIUS = 1;
int16_t snakeLength = 1;
Segment snake[SNAKE_MAX_LENGTH];
DIRECTION direction = LEFT;

int16_t snakeScore = 0;

int16_t foodRadius = 2;
int16_t foodX = 1;
int16_t foodY = 1;
bool toGenerate = true;
bool foodEaten = false;
COLLISION collision = COLLIDE_NONE;

bool gameReset = true;
bool prevSelectState = false;

unsigned long lastMove = 0;
const unsigned long moveInterval = 100;