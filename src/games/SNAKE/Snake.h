#ifndef SNAKE_H
#define SNAKE_H

/* Function Definitions */
void setSnakeDirection(void);
void moveSnake(void);
void drawSnake(void);
void snakeGrow(void);
void getFoodCoords(int16_t &foodX, int16_t &foodY);
void drawFood(void);
bool checkFoodCollision(int16_t snakeX, int16_t snakeY, int16_t foodX, int16_t foodY);
bool checkSelfCollision(void);
void destroyFood(void);

// Main Functions
void SnakeInit(void);
void SnakeUpdate(void);

#endif