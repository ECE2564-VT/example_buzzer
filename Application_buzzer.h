/*
 * Application_buzzer.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Matthew Zhong
 *      Modified: Leyla Nazhand-ali (November 2021)
 */

#ifndef APPLICATION_BUZZER_H_
#define APPLICATION_BUZZER_H_

#include <HAL/Graphics.h>
#include <HAL/HAL.h>
#include <HAL/Timer.h>

enum _LEDState
{
    LED_INIT,
    LED_L1,
    LED_L2_RED,
    LED_L2_GREEN,
    LED_L2_BLUE,
    LED_B_RED,
    LED_B_GREEN,
    LED_B_BLUE
};
typedef enum _LEDState LEDState;

enum _StopWatchState { STOPPED, MEASURING_TIME };
typedef enum _StopWatchState StopWatchState;

struct _BuzzerApp
{
    GFX gfx;  //gfx stands for grahics!!!

    // Buzzer FSM
    // -------------------------------------------------------------------------
    // To keep track of which comptete note is playing, we need a CompleteNote
    // object. To alternate note sounds in a beeping fashion, we use a separate
    // boolean. Finally, to keep track of which note to change to, we keep track
    // of the Note and octave in their own separate variables. We also keep a
    // boolean for whether the buzzer is muted or not
    Note note;
    int octave;
    CompleteNote completeNote;
    bool playSilent;
    bool mute;

};
typedef struct _BuzzerApp BuzzerApp;

BuzzerApp BuzzerApp_construct();
void BuzzerApp_loop(BuzzerApp* app, HAL *hal);


// FSM functions for the Buzzer demo
void BoardTest_setupFSM_Buzzer(BuzzerApp* app);
void BoardTest_loopFSM_Buzzer(BuzzerApp* app);


#endif /* APPLICATION_BUZZER_H_ */
