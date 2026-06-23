#ifndef HARDWARE_H
#define HARDWARE_H

    #if !defined(EMULATOR_BUILD) && !defined(DEVICE_BUILD)
    #error "Define EMULATOR_BUILD or DEVICE_BUILD"
    #endif

    #if defined(EMULATOR_BUILD) && defined(DEVICE_BUILD)
    #error "Only one build type allowed"
    #endif

    void initHardware(void);

    // ==== Common Definitions ====
    
    // OLED Definition

    #define SCREEN_WIDTH 128  
    #define SCREEN_HEIGHT 64  
    #define OLED_RESET    -1  
    #define SCREEN_ADDRESS 0x3C  // For THIS model of the display
    // #define WHITE 1

    #ifdef EMULATOR_BUILD

        #include <Adafruit_SSD1306.h>
        extern Adafruit_SSD1306 display;
        #define DISPLAY_WHITE SSD1306_WHITE

        // Wire Definition

        #define SDA 22
        #define SCL 23

        // Joystick Definition
        
        #define JOY_X 2
        #define JOY_Y 15
        #define JOY_SEL 4

    #elif defined(DEVICE_BUILD)
        #include <Adafruit_SH110X.h>
        extern Adafruit_SH1106G display;
        #define DISPLAY_WHITE SSH110X_WHITE

        // Wire Definition
        
        #define SDA 21
        #define SCL 22

        // Button Definition

        #define BUTTON_UP 15
        #define BUTTON_DOWN 23
        #define BUTTON_LEFT 4
        #define BUTTON_RIGHT 5
        #define BUTTON_SEL 18

        // Audio - Passive Buzzer
        
        #define BUZZER 2

    #endif

#endif