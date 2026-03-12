/* Buttons must use pull-up or pull-down resistors to ensure no flakey current flows through back to the system, causing disruption of the flow of logic.*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Arduino.h>

#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET    -1  
#define SCREEN_ADDRESS 0x3C  // For THIS model of the display

#define BUTTON1 5
#define BUTTON2 18

#define FRAME_TIME 16  // ~16ms per frame for 60 FPS
unsigned long lastFrameTime = 0;

#define DEBOUNCE_DELAY 50  // 50ms debounce time
unsigned long lastDebounceTime = 0;

void playerPaddle(int16_t, int16_t, int16_t, int16_t);
void enemyPaddle(int16_t, int16_t, int16_t, int16_t);
void ballObject(int16_t, int16_t, int16_t);
void enemyAI();
void mainMenu();
void gameOver();
void youWon();
void dividerLines();

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* Ball Data */
int16_t ballX = 62; // 128/2 - radius
int16_t ballY = 30; // Width/2 - radius
int16_t ballRadius = 2;
int16_t ballVelX = 2;
int16_t ballVelY = 2;

/* Player Paddle Data */
int16_t playerX = 2;
int16_t playerY = 24; // 64/2 - 16/2
int16_t playerWidth = 3;
int16_t playerHeight = 20;
int16_t paddleSpeed = 4;

/* Enemy Paddle Data */
int16_t enemyX = 123;
int16_t enemyY = 24;
int16_t enemyWidth = 3;
int16_t enemyHeight = 20;
// ----------------------
int16_t enemySpeed1 = 2;
int16_t enemySpeed2 = 4;
int16_t enemySpeed3 = 6;

bool isMainMenu = true;
int16_t alt = 1;

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  Wire.begin(21, 22);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  // pinMode(21, OUTPUT);

  if (!display.begin(SCREEN_ADDRESS, OLED_RESET))
  {
    Serial.println(F("SH1106G allocation failed"));
    for (;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(10, 10);
  display.println("Starting...");
  display.display();
  delay(1000);
  display.clearDisplay();

}

void loop()
{
  if (millis() - lastFrameTime < FRAME_TIME) {
    return;  // Skip frame if not enough time has passed
  }
  lastFrameTime = millis();  // Update last frame time

  // Show main menu at first
  mainMenu();
  // Has internal display.display()

  if (digitalRead(BUTTON1) == LOW) // UP button
  {
    if (playerY > 0)
    {
      playerPaddle(playerX, playerY-=paddleSpeed, playerWidth, playerHeight);
    }

    //delay(10);
  }
  else if (digitalRead(BUTTON2) == LOW) // DOWN button
  {
    if (playerY+playerHeight < 64)
    {
      playerPaddle(playerX, playerY+=paddleSpeed, playerWidth, playerHeight);
    }

    //delay(10);
  }

  display.clearDisplay();

  // Screen Boundary
  display.drawRect(0, 0, 128, 64, 1);

  playerPaddle(playerX, playerY, playerWidth, playerHeight);

  enemyPaddle(enemyX, enemyY, enemyWidth, enemyHeight);

  ballObject(ballX-=ballVelX, ballY-=ballVelY, ballRadius);

  enemyAI();

  dividerLines();

  if ((ballY >= (63-ballRadius)) || (ballY < (1+ballRadius)))
  {
    // Ball Y bounce
    ballVelY *= -1;
  }

  if (
    ((ballX >= (123-ballRadius)) && ((ballY >= enemyY) && (ballY <= enemyY+enemyHeight))) || ((ballX < (3+playerWidth+ballRadius)) && ((ballY >= playerY) && (ballY <= playerY+playerHeight)))
    )
  {
    // Ball X bounce
    // Use Counter here, and after 10 collisions, increase x/y velocity.
    ballVelX *= -1;
  }

  // Could use a compact function call instead of ifs...###########################
  if (ballX <= 0)
  {
    // Player missed the ball
    display.clearDisplay();

    gameOver();
  }

  if (ballX >= 128)
  {
    // Enemy missed the ball
    display.clearDisplay();
    youWon();
  }

  display.display();
  //delay(10);
}

void ballObject(int16_t x, int16_t y, int16_t r)
{
  display.fillCircle(x, y, ballRadius, 1);
}

void playerPaddle(int16_t x, int16_t y, int16_t w, int16_t h)
{
  display.fillRect(x, y, w, h, 1);
}

void enemyPaddle(int16_t x, int16_t y, int16_t w, int16_t h)
{
  display.fillRect(x, y, w, h, 1);
}

void enemyAI()
{
  /* The idea is to try to match the ball's Y coord, with the center of the paddle
   enemyY -= paddleSpeed, when the ball is in enemy court until ballY is reached...
   Three different levels, 1 -> slowly gets there, 2 -> faster, 3 -> perfect */

  if (ballX >= SCREEN_WIDTH/2)
  {
    // Ball is in enemy court

    if (ballVelY > 0)
    {
      // Ball going upwards
      if (enemyY >= 0)
        enemyPaddle(enemyX, enemyY-=enemySpeed1, enemyWidth, enemyHeight);
    }
    else
    {
      // Ball going downwards
      if (enemyY+enemyHeight <= SCREEN_HEIGHT)
        enemyPaddle(enemyX, enemyY+=enemySpeed1, enemyWidth, enemyHeight);
    }
  }
}

void dividerLines()
{
  for (int y=0; y<=SCREEN_HEIGHT; y+=2)
  {
    display.drawPixel(SCREEN_WIDTH/2 - 1, y, 1);
    display.drawPixel(SCREEN_WIDTH/2 + 1, y, 1);
  }
}

void mainMenu()
{
  while(isMainMenu)
  {
    display.clearDisplay();

    display.drawRect(0, 0, 128, 64, 1);

    display.setTextSize(1);
    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 - 4);

    // Rectangle around text for selection
    // 128/2 = 64, 64 - 6+6+3 = 49, 49 - 4(padding) = 45
    // 64/2 = 32, 32 - 4 = 28, 28 - 4(padding) = 24
    if (alt == 1)
      display.drawRect(45, 24, 32, 14, 1);
    else if (alt == -1)
      display.drawRect(45, 24 + 14, 32, 14, 1);

    display.print("PLAY");

    display.setCursor(SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT/2 + 9);
    display.print("EXIT");

    if (digitalRead(BUTTON1) == LOW)
    {
      if (millis() - lastDebounceTime > DEBOUNCE_DELAY)
      {
        isMainMenu = false;
      }
    }

    if (digitalRead(BUTTON2) == LOW)
    {
      if (millis() - lastDebounceTime > DEBOUNCE_DELAY)
      {
        alt *= -1;
        lastDebounceTime = millis();  // Update last debounce time
      }
    }

    display.display();
  }
}

void gameOver()
{
  display.setTextSize(1);
  display.setCursor(SCREEN_WIDTH/2 - 9*6/2, SCREEN_HEIGHT/2 - 4);
  display.print("Game Over");
  display.display();
  
  delay(2000);
  mainMenu();
}

void youWon()
{
  display.setTextSize(1);
  display.setCursor(SCREEN_WIDTH/2 - 8*6/2, SCREEN_HEIGHT/2 - 4);
  display.print("You Won!");
  display.display();

  delay(2000);
  mainMenu();
}