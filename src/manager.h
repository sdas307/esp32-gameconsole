#ifndef MANAGER_H
#define MANAGER_H

enum GAME_SELECTED
{
    GAME_NONE,
    GAME_PONG,
    GAME_SNAKE,
    GAME_DINO,
    GAME_SPACE_WARS
};

enum HOVERED_APP
{
  HOVERED_GAMES,
  HOVERED_SETTINGS
};

enum APP_STATE
{
  STATE_HOME,
  STATE_GAME,
  STATE_SETTINGS
};

extern enum GAME_SELECTED currentGameSelected;
extern enum HOVERED_APP currentHover;
extern enum APP_STATE currentState;

#endif