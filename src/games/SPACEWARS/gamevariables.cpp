#include "gamevariables.h"
#include "hardware.h"
#include "input/input.h"
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

void drawSprite(const Sprite *sprite)
{
    display.drawBitmap(sprite->x, sprite->y, sprite->sprites[sprite->spriteIndex], sprite->width, sprite->height, WHITE);
}

void spriteUpdate(Sprite *sprite, uint16_t duration)
{
    if (sprite->spriteCount > 1)
    {
        unsigned long currentTime = millis();

        if ((currentTime - sprite->lastFrameTime) >= duration)
        {
            sprite->spriteIndex++;
            sprite->lastFrameTime = currentTime;
        }

        if (sprite->spriteIndex >= sprite->spriteCount)
            sprite->spriteIndex = 0;

    }
}

bool spaceWarsCheckCollision(void)
{
    return false;
}