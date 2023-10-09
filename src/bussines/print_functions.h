#ifndef __PRINT_FUNCTIONS__H__
#define __PRINT_FUNCTIONS__H__
#include <Arduino.h>
#include "model/scoreObj.h"

void printValues(ScoreOBJ *scoreObj);
void popularBitsScore1(byte *display, int score);
void popular(int desena,int sentena,byte *display);
void popularBitsScore2(byte *display, int score);
void updateSiftRegister(byte enviarBits, int stcp, int ds, int shcp);
void blinkLed();

#endif //!__PRINT_FUNCTIONS__H__