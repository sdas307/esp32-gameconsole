#ifndef INPUT_H
    #define INPUT_H

    #define IDLE_JOYSTICK_VALUE 2048

    void initInput();

    bool upPressed();
    bool downPressed();
    bool leftPressed();
    bool rightPressed();
    bool selectPressed();

#endif