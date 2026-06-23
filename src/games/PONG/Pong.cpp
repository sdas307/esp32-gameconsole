/* Buttons must use pull-up or pull-down resistors to ensure no flakey current flows through back to the system, causing disruption of the flow of logic.*/

#include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include "hardware.h"
#include "input.h"
#include "paddle.h"
#include "ball.h"
#include "gamevariables.h"
#include "mainmenu.h"
#include "Pong.h"

void PongInit(void)
{
  // Reset ball
  ballX = 62;
  ballY = 30;
  ballVelX = 3;
  ballVelY = 3;

  // Reset paddles
  playerY = 24;
  enemyY = 24;

  // Reset levels
  hitCounter = 0;
  playerScore = 0;
  levelCount = 1;
}

void PongUpdate(void)
{
  // Show main menu at first
  if (pongGameState == PONG_MAIN_MENU)
  {
    pongMainMenu();
    PongInit();
  }

  if (pongGameState == PONG_PLAY)
  {
    if (upPressed()) // UP direction
    {
      if (playerY > 0)
      {
        playerY -= paddleSpeed;
      }
    }
    else if (downPressed()) // DOWN direction
    {
      if ((playerY + playerHeight) < 64)
      {
        playerY += paddleSpeed;
      }
    }

    // Screen Boundary
    display.drawRect(0, 0, 128, 64, 1);

    drawPlayerPaddle(playerX, playerY, playerWidth, playerHeight);

    drawEnemyPaddle(enemyX, enemyY, enemyWidth, enemyHeight);

    drawBall(ballX-=ballVelX, ballY-=ballVelY, ballRadius);

    enemyAI();

    dividerLines();

    if ((ballY >= (63-ballRadius)) || (ballY < (1+ballRadius)))
    {
      // Ball Y bounce
      ballVelY *= -1;
    }

    if ((ballX >= (123-ballRadius)) && ((ballY >= enemyY) && (ballY <= enemyY+enemyHeight)))
    {
      // Enemy hits the ball
      hitCounter++;
      ballVelX *= -1;
    }

    if ((ballX < (3+playerWidth+ballRadius)) && ((ballY >= playerY) && (ballY <= playerY+playerHeight)))
    {
      // Player hits the ball
      hitCounter++;
      playerScore++;
      ballVelX *= -1;
    }

    if ((levelCount == 1) && (hitCounter == hitLevel1))
    {
      level2();
      ++levelCount;
    }
    if ((levelCount == 2) && (hitCounter == hitLevel2))
    {
      level3();
      ++levelCount;
    }

    if (ballX <= 0)
    {
      // Player missed the ball
      delay(1000);
      pongGameState = PONG_HI_SCORE;
    }

    if (ballX >= 128)
    {
      // Enemy missed the ball
      delay(1000);
      pongGameState = PONG_HI_SCORE;
    }
  }

  if (pongGameState == PONG_HI_SCORE)
  {
    highScore();
  }
}