#include <Adafruit_GFX.h>
#include <stdint.h>
#include "hardware.h"
#include "input.h"
#include "gamevariables.h"
#include "Snake.h"
#include "mainmenu.h"
#include "hiscore.h"

bool isGameOver = false;

void SnakeInit()
{
    snake[0] = {64, 32};
}

void SnakeUpdate()
{
    if (gameState == MAIN_MENU)
    {
        snakeMainMenu();
    }

    if (gameState == PLAY)
    {
        if (gameReset)
        {
            SnakeInit();
            gameReset = false;
        }

        setSnakeDirection();

        // Simple choppy bit-by-bit moevement
        if (millis() - lastMove >= moveInterval)
        {
            moveSnake();
            lastMove = millis();
        }

        if (checkSelfCollision())
            gameState = HI_SCORE;

        drawSnake();
        destroyFood();
        drawFood();
    }

    if (gameState == HI_SCORE)
    {
       snakeHiScore();
    }

    // Update the scene
    //display.display();
}

void setSnakeDirection()
{
    if (leftPressed() && direction != RIGHT)
    {
        direction = LEFT;
    }
    else if (rightPressed() && direction != LEFT)
    {
        direction = RIGHT;
    }
    else if (upPressed() && direction != DOWN)
    {
        direction = UP;
    }
    else if (downPressed() && direction != UP)
    {
        direction = DOWN;
    }
}

void moveSnake()
{
    // Moves the body and tail
    for (int i = snakeLength-1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }

    // Moves the head
    switch (direction)
    {
    case UP:
        snake[0].y -= SEGMENT_SIZE;
        break;

    case DOWN:
        snake[0].y += SEGMENT_SIZE;
        break;

    case LEFT:
        snake[0].x -= SEGMENT_SIZE;
        break;

    case RIGHT:
        snake[0].x += SEGMENT_SIZE;
        break;
    
    default:
        break;
    }
}

void drawSnake()
{
    for (int i = 0; i < snakeLength; i++)
    {
        // Left Outside Screen
        if (snake[0].x < 0)
            snake[0].x = 127;

        // Right Outside Screen
        if (snake[0].x > 128)
            snake[0].x = 1;

        // Top Outside Screen
        if (snake[0].y < 0)
            snake[0].y = 63;

        // Bottom Outside Screen
        if (snake[0].y > 64)
            snake[0].y = 0;

        display.fillRoundRect(snake[i].x, snake[i].y, SEGMENT_SIZE, SEGMENT_SIZE, SEGMENT_RADIUS, DISPLAY_WHITE);
    }
}

void snakeGrow()
{
    snake[snakeLength] = snake[snakeLength - 1];
    snakeLength++;
}

void getFoodCoords(int16_t &foodX, int16_t &foodY)
{
    bool valid = false;
    int16_t safety = 100;

    while (!valid && safety-- > 0)
    {
        int16_t getFood_x = random(2, 122);
        int16_t getFood_y = random(2, 58);
        
        valid = true;

        for (int i = 0; i < snakeLength; i++)
        {
            // Food (x, y) is on the snake segment
            if (snake[i].x == getFood_x && snake[i].y == getFood_y)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            foodX = getFood_x;
            foodY = getFood_y;
        }

        if (safety <= 0)
        {
            foodX = 2;
            foodY = 2;
        }
    }
}

void drawFood()
{
    if (foodEaten == true)
    {
        toGenerate = true;
        foodEaten = false;
    }

    if (toGenerate)
    {
        getFoodCoords(foodX, foodY);
        toGenerate = false;
    }

    display.fillCircle(foodX, foodY, foodRadius, DISPLAY_WHITE);
}

void destroyFood()
{
    if (checkFoodCollision(snake[0].x, snake[0].y, foodX, foodY))
    {
        foodEaten = true;
        snakeScore++;
        snakeGrow();
    }
}

bool checkFoodCollision(int16_t snakeX, int16_t snakeY, int16_t foodX, int16_t foodY)
{
    int16_t foodLeft = foodX - foodRadius;
    int16_t foodRight = foodX + foodRadius;
    int16_t foodTop = foodY - foodRadius;
    int16_t foodBottom = foodY + foodRadius;

    int16_t snakeLeft = snakeX;
    int16_t snakeRight = snakeX + SEGMENT_SIZE;
    int16_t snakeTop = snakeY;
    int16_t snakeBottom = snakeY + SEGMENT_SIZE;

    return (
        foodRight > snakeLeft &&
        foodLeft < snakeRight &&
        foodBottom > snakeTop &&
        foodTop < snakeBottom
    );
}

bool checkSelfCollision()
{
    for (int i = 2; i < snakeLength; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}