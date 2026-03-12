#include "cactuslogic.h"
#include "hardware.h"
#include "gamevariables.h"
#include "../../assets/games/dino/dino_sprites.h"

// Cactus Definition
int16_t cactusSmallPosY = 43;
int16_t cactusLargePosY = 40;

typedef struct
{
    int16_t x;
    CactusType type;
    bool active;
} Cactus;

static Cactus cactus;

void drawCactusSmall(int16_t cactusX)
{
    display.drawBitmap(cactusX, cactusSmallPosY, epd_bitmap_cactus_small, 8, 14, WHITE);
}

void drawCactusLarge(int16_t cactusX)
{
    display.drawBitmap(cactusX, cactusLargePosY, epd_bitmap_cactus_large, 8, 17, WHITE);
}

void drawCactus()
{
    if (!cactus.active)
        return;

    switch (cactus.type)
    {
        case CACTUS_SMALL:
            drawCactusSmall(cactus.x);
            break;

        case CACTUS_LARGE:
            drawCactusLarge(cactus.x);
            break;
    }
}

void spawnCactus()
{
    // gap-based spawn
    cactus.x = 128 + random(-24, 16);
    cactus.active = true;

    int16_t r = random(0, 100);
    if (r < 70)
        cactus.type = CACTUS_SMALL;
    else
        cactus.type = CACTUS_LARGE;
}

// int16_t cactusSizeProbabilityGenerator()
// {
//     cactusSizeProbability = random(pMin, pMax+1);

//     return cactusSizeProbability;
// }
// int16_t cactusSpawnProbabilityGenerator()
// {
//     cactusSpawnProbability = random(pMin, pMax+1);

//     return cactusSpawnProbability;
// }

void updateCactus()
{
    if (!cactus.active)
    {
        spawnCactus();
        return;
    }
        
    cactus.x -= gameSpeed;

    if (cactus.x < -8)   // fully off-screen with extra padding
    {
        cactus.active = false;
        spawnCactus();
    }
}

void resetCactus()
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