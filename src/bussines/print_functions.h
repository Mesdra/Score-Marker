#ifndef __PRINT_FUNCTIONS__H__
#define __PRINT_FUNCTIONS__H__
#include <Arduino.h>
#include "model/scoreObj.h"

void printValues(ScoreOBJ *scoreObj);
void popularBits(byte *display, int score);
void updateSiftRegister(byte enviarBits, int stcp, int ds, int shcp);

#endif //!__PRINT_FUNCTIONS__H__