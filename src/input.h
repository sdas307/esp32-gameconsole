#ifndef INPUT_H
#define INPUT_H

#define IDLE_JOYSTICK_VALUE 2048

void initInput(void);

/** Returns true if UP is pressed. */
bool upPressed(void);

/** Returns true if DOWN is pressed. */
bool downPressed(void);

/** Returns true if LEFT is pressed. */
bool leftPressed(void);

/** Returns true if RIGHT is pressed. */
bool rightPressed(void);

/** Returns true if SELECT is pressed. */
bool selectPressed(void);

#endif