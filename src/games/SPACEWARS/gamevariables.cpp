#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "../../assets/games/spacewars/spacewars_sprites.h"

SPACEWARS_GAME_STATE spaceWarsGameState;

float bottomPadding = SCREEN_HEIGHT - 4; // At Spaceship's y=0

int16_t spaceWarsgameSpeed = 5;
unsigned long spaceWarsLastUpdate = 0;

uint16_t spaceWarsScore = 0;
char spaceWarsScoreText[10];

void drawScreenBoundary(void)
{
    display.drawRect(0, 0, 128, 64, WHITE);
}

bool spaceWarsCheckCollision(void)
{
    return false;
}