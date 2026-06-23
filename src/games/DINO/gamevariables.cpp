#include "gamevariables.h"
#include "hardware.h"
#include "input.h"
#include "cactuslogic.h"
#include "../../assets/games/dino/dino_sprites.h"

DINO_GAME_STATE dinoGameState;

int16_t dinoFrameAlt = 1;
float groundLevel = 39; // At Dino's Y=0

/*
DinoY = 39
   _
  | |
  ---
  | |
  __________________Ground (AbsoluteValue) = (DinoY + DinoHeight)
*/

typedef struct
{
    float x;
    float y;
    float velocity;
    float jumpStrength;
    float gravity;
} Dino;

static Dino dino =
{
    .x = 16,
    .y = 39,
    .velocity = 0,
    .jumpStrength = 8,
    .gravity = 1.1
};


/* Dino Initial Position */

float dinoPosX = 16;
float dinoPosY = 39;
float dinoVelY = 0;
float jumpStrength = 8;
float gravity = 1.1;

int16_t gameSpeed = 5;
unsigned long lastUpdate = 0;

uint16_t score = 0;
char scoreText[10];

/* Function Definitions */

void drawGround(void)
{
    display.drawLine(0, 57, 128, 57, WHITE);
}
void spawnDino()
{
    dino.x = 16;
    dino.y = 39;
    dino.velocity = 0;
    dino.jumpStrength = 8;
    dino.gravity = 1.1;
}

void drawDino(void)
{
    if (dino.y != groundLevel)
        display.drawBitmap(dino.x, dino.y, bitmap_dino0, 16, 18, WHITE);
    else
    {
        if (dinoFrameAlt == 1)
        {
            display.drawBitmap(dino.x, dino.y, bitmap_dino1, 16, 18, WHITE);
            dinoFrameAlt *= -1;
        }

        else if (dinoFrameAlt == -1)
        {
            display.drawBitmap(dino.x, dino.y, bitmap_dino2, 16, 18, WHITE);
            dinoFrameAlt *= -1;
        }
    }
}

void dinoMove(void)
{
    if (upPressed() && dino.y == groundLevel)
    {
        dino.velocity = -(dino.jumpStrength);
    }

    if (downPressed() && dino.y != groundLevel)
    {
        dino.velocity = dino.jumpStrength;
    }
    
    dino.velocity += dino.gravity;

    dino.y += dino.velocity;

    /* Clamp Dino on the ground upon feet touching */
    if (dino.y >= groundLevel)
    {
        dino.y = groundLevel;
        dino.velocity = 0;
    }

}

void drawScore(void)
{
    unsigned long now = millis();

    display.setCursor(3, 3);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (now - lastUpdate >= 50)
    {
        score++;
        lastUpdate = now;
    }

    // Update scoreText to have a padding of 5 0's
    sprintf(scoreText, "%05d", score);

    display.print(scoreText);
}

bool checkCollision(void)
{
    int16_t dinoFeetX = dino.x + 8;
    int16_t dinoFeetY = dino.y + 18;
    int16_t dinoFaceX = dino.x + 16;
    int16_t dinoFaceY = dino.y;

    if (!cactusIsActive())
        return false;

    int16_t cactusX = cactusGetX();
    int16_t cactusY;
    CactusType type = cactusGetType();

    if (type == CACTUS_SMALL)
        cactusY = 43;
    else if (type == CACTUS_LARGE)
        cactusY = 40;

    if (cactusX < dinoFaceX-3-gameSpeed && cactusY < dinoFeetY-2 && !(cactusX+8 < dinoPosX))
        return true;
    else
        return false;

    // OG hand-made function -> let's not remove it?
    // if ((cactusX1 < dinoFaceX-3-gameSpeed && cactusY1 < dinoFeetY-2 && !(cactusX1+8 < dinoPosX))
    // || (cactusX2 < dinoFaceX-3-gameSpeed && cactusY2 < dinoFeetY-2 && !(cactusX2+8 < dinoPosX)))
    //     return true;
    // else
    //     return false;
}