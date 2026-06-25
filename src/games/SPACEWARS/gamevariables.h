#ifndef SPACEWARS_GAMEVARIABLES_H
#define SPACEWARS_GAMEVARIABLES_H

#include <stdint.h>

#define SPACESHIP_WIDTH 13
#define SPACESHIP_HEIGHT 14

/** Represents a Sprite. */
typedef struct Sprite
{
    /** Spriteset of the spaceship. */
    const uint8_t* const* sprites;

    /** Total sprites in the spriteset. */
    const uint8_t spriteCount;

    /** Index of the sprite to draw. */
    uint8_t spriteIndex;

    /** To be used to update sprite based on time passed. */
    unsigned long lastFrameTime;

    /** Width of the spaceship in pixels. */
    uint8_t width;

    /** Height of the spaceship in pixels. */
    uint8_t height;

    /** X position of the spaceship in pixels. */
    int16_t x;

    /** Y position of the spaceship in pixels. */
    int16_t y;

    /** Horizontal movement direction
     * (-1 = left, 1 = right). */
    int8_t direction;

    /** Horizontal movement speed in pixels per update. */
    int16_t speed;
} Sprite;

// extern Sprite Spaceship;
extern Sprite Enemy;
extern Sprite Jango;
extern Sprite Jango1;

/* Enum Definitions */

/** Possible game states for Space Wars. */
enum SPACEWARS_GAME_STATE
{
    /** Gameplay screen. */
    SPACEWARS_PLAY,

    /** High score screen. */
    SPACEWARS_HI_SCORE
};

extern SPACEWARS_GAME_STATE spaceWarsGameState;

extern float bottomPadding;

extern int16_t gameSpeed;
extern uint16_t score;
extern char scoreText[];

/**
 * Draw screen boundary (Rectangle - Screen Width x Screen Height).
 */
void drawScreenBoundary(void);

/** Draw sprite at its current position.
 * @param sprite Sprite to draw.
 */
void drawSprite(const Sprite *sprite);

/** Update sprite based on time passed.
 * @param sprite Sprite to update.
 * @param duration Duration to update after.
 */
void spriteUpdate(Sprite *sprite, uint16_t duration);

bool checkCollision(void);

#endif