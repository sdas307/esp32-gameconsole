#include "cactuslogic.h"
#include "hardware.h"
#include "gamevariables.h"
#include "../../assets/games/dino/dino_sprites.h"

// Cactus Definition
const int16_t cactusSmallPosY = 43;
const int16_t cactusLargePosY = 40;

typedef struct
{
    int16_t x;
    int16_t y;
    CactusType type;
    bool active;
} Cactus;

static Cactus cactus;

static void drawCactusSmall(const Cactus *cactus)
{
    display.drawBitmap(cactus->x, cactus->y, bitmap_cactus_small, 8, 14, DISPLAY_WHITE);
}

static void drawCactusLarge(const Cactus *cactus)
{
    display.drawBitmap(cactus->x, cactus->y, bitmap_cactus_large, 8, 17, DISPLAY_WHITE);
}

void drawCactus(void)
{
    if (!cactus.active)
        return;

    switch (cactus.type)
    {
        case CACTUS_SMALL:
            drawCactusSmall(&cactus);
            break;

        case CACTUS_LARGE:
            drawCactusLarge(&cactus);
            break;
    }
}
CactusType randomCactusType(void)
{
    long r = random(0, 100);
    if (r < 70)
        return CACTUS_SMALL;
    else
        return CACTUS_LARGE;
}

static void spawnCactus(Cactus *cactus)
{
    // gap-based spawn
    cactus->x = SCREEN_WIDTH + random(-24, 16);
    cactus->active = true;

    cactus->type = randomCactusType();

    switch (cactus->type)
    {
        case CACTUS_SMALL:
            cactus->y = 43;
            break;
        case CACTUS_LARGE:
            cactus->y = 40;
            break;
    }
}

void updateCactus(void)
{
    if (!cactus.active)
    {
        spawnCactus(&cactus);
        return;
    }
        
    cactus.x -= gameSpeed;

    if (cactus.x < -8)   // fully off-screen with extra padding
    {
        cactus.active = false;
        spawnCactus(&cactus);
    }
}

void resetCactus(void)
{
    cactus.x = 128;
    cactus.active = false;
    cactus.type = CACTUS_SMALL;
}

/* Public Queries (Getters) */

bool cactusIsActive()
{
    return cactus.active;
}

int16_t cactusGetX()
{
    return cactus.x;
}

CactusType cactusGetType()
{
    return cactus.type;
}

// void slidingCactus()
// {
//     if (cactusSizeProbability < 7)
//     {
//         drawCactusSmall();
//         cactusSmallPosX -= gameSpeed;
        
//         if (cactusSmallPosX <= -8)
//         {
//             cactusSmallPosX = 128;
//             cactusSizeProbability = cactusSizeProbabilityGenerator();
//         }
//     }
//     else if (cactusSizeProbability >= 7)
//     {
//         drawCactusLarge();
//         cactusLargePosX -= gameSpeed;
        
//         if (cactusLargePosX <= -8)
//         {
//             cactusLargePosX = 128;
//             cactusSizeProbability = cactusSizeProbabilityGenerator();
//         }
//     }
// }