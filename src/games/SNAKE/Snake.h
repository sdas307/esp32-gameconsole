
/* Function Definitions */
void setSnakeDirection();
void moveSnake();
void drawSnake();
void snakeGrow();
void getFoodCoords(int16_t &foodX, int16_t &foodY);
void drawFood();
bool checkFoodCollision(int16_t snakeX, int16_t snakeY, int16_t foodX, int16_t foodY);
bool checkSelfCollision();
void destroyFood();

// Main Functions
void SnakeInit();
void SnakeUpdate();