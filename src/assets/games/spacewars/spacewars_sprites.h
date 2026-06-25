#ifndef SPACEWARS_SPRITES_H
#define SPACEWARS_SPRITES_H

#include <Arduino.h>

#define BITMAP_SPACESHIP_WIDTH 13
#define BITMAP_SPACESHIP_HEIGHT 13

#define BITMAP_ENEMY_WIDTH 7
#define BITMAP_ENEMY_HEIGHT 9

extern const uint8_t PROGMEM bitmap_spaceship[];
extern const uint8_t PROGMEM bitmap_enemy[];
extern const uint8_t PROGMEM bitmap_jango0[];
extern const uint8_t PROGMEM bitmap_jango1[];

extern const uint8_t* const bitmap_JangoSprites[];
extern const uint8_t bitmap_JangoSprites_LEN;

extern const uint8_t* const bitmap_EnemySprites[];
extern const uint8_t bitmap_EnemySprites_LEN;

extern const uint8_t* const bitmap_SpaceshipSprites[];
extern const uint8_t bitmap_SpaceshipSprites_LEN;

#endif