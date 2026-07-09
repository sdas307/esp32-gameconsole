#include "hardware.h"
#include "input/input.h"
#include "manager.h"
#include "assets/game icons/game_icons.h"
#include "games/PONG/Pong.h"
#include "games/SNAKE/Snake.h"
#include "games/DINO/dino.h"
#include "games/SPACEWARS/spacewars.h"

typedef struct
{
  /** Currently highlighted game icon. */
  int16_t selected;

  /** True when a user is browing games list. */
  bool notSelected;

  /** Button edge-detection state. */
  bool currLeftPressed;
  bool prevLeftPressed;
  bool currRightPressed;
  bool prevRightPressed;

} GameManagerState;

// Only notSelected is set to true, rest default to false values on static declaration
static GameManagerState gameManagerState = {.notSelected = true};

// An alias for gameManagerState
static GameManagerState &gms = gameManagerState;

static bool leftJustPressed(void);
static bool rightJustPressed(void);
static void drawIconDino();
static void drawIconPong();
static void drawIconSnake();
static void drawIconSpaceWars();

void GameManager(void)
{
  if (gameManagerState.notSelected)
  {
    // Show Game Icons
    drawIconDino();
    drawIconPong();
    drawIconSnake();
    display.drawBitmap(1, 18, bitmap_left_slider_arrow, 7, 14, DISPLAY_WHITE);
    display.drawBitmap(SCREEN_WIDTH - 1 - 7, 18, bitmap_right_slider_arrow, 7, 14, DISPLAY_WHITE);

    gms.currLeftPressed = leftPressed();
    gms.currRightPressed = rightPressed();

    if (rightJustPressed() && gms.selected != 3)
    {
      gms.selected += 1;
      gms.prevRightPressed = true;
    }
    else if (rightJustPressed())
    {
      gms.selected = 0;
      gms.prevRightPressed = true;
    }

    if (leftJustPressed() && gms.selected != 0)
    {
      gms.selected -= 1;
      gms.prevLeftPressed = true;
    }
    else if (leftJustPressed())
    {
      gms.selected = 3;
      gms.prevLeftPressed = true;
    }

    if (gms.selected == 3)
    {
      display.clearDisplay();
      drawIconSpaceWars();
      display.drawBitmap(1, 18, bitmap_left_slider_arrow, 7, 14, DISPLAY_WHITE);
    }

    /** Draw a line under selected game name,
     * check for select button press,
     * and switch notSelected to false
     */
    switch (gms.selected)
    {
    case 0:
      display.drawFastHLine(16, 48, 16, DISPLAY_WHITE);
      if (selectPressed())
      {
        gms.notSelected = false;
        currentGameSelected = GAME_DINO;
      }
      break;

    case 1:
      display.drawFastHLine(55, 48, 19, DISPLAY_WHITE);
      if (selectPressed())
      {
        gms.notSelected = false;
        currentGameSelected = GAME_PONG;
      }
      break;

    case 2:
      display.drawFastHLine(93, 48, 22, DISPLAY_WHITE);
      if (selectPressed())
      {
        gms.notSelected = false;
        currentGameSelected = GAME_SNAKE;
      }
      break;

    case 3:
      display.drawFastHLine(13, 48, 22, DISPLAY_WHITE);
      if (selectPressed())
      {
        gms.notSelected = false;
        currentGameSelected = GAME_SPACE_WARS;
      }
      break;

    default:
      break;
    }

    gms.prevLeftPressed = gms.currLeftPressed;
    gms.prevRightPressed = gms.currRightPressed;
  }

  switch (currentGameSelected)
  {
  case GAME_PONG:
    PongUpdate();
    break;

  case GAME_SNAKE:
    SnakeUpdate();
    break;

  case GAME_DINO:
    DinoUpdate();
    break;

  case GAME_SPACE_WARS:
    SpaceWarsUpdate();
    break;

  default:
    break;
  }
}

static bool leftJustPressed(void)
{
  return (gms.currLeftPressed && !gms.prevLeftPressed);
}

static bool rightJustPressed(void)
{
  return (gms.currRightPressed && !gms.prevRightPressed);
}

static void drawIconDino()
{
    display.drawBitmap(10, 11, bitmap_games_icon[0], 28, 36, DISPLAY_WHITE);
    
}

static void drawIconPong()
{
    display.drawBitmap(50, 11, bitmap_games_icon[1], 28, 36, DISPLAY_WHITE);
}
    
static void drawIconSnake()
{
    display.drawBitmap(90, 11, bitmap_games_icon[2], 28, 36, DISPLAY_WHITE);
}

static void drawIconSpaceWars()
{
    display.drawBitmap(10, 11, bitmap_space_wars_icon, 28, 36, DISPLAY_WHITE);
}