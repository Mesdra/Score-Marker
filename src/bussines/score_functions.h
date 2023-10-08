#ifndef __SCORE_FUNCTIONS__H__
#define __SCORE_FUNCTIONS__H__
#include <Arduino.h>
#include "model/scoreObj.h"

void changeGameMode(ScoreOBJ *scoreObj);
void addScore(ScoreOBJ *scoreObj, int team);
void subScore(ScoreOBJ *scoreObj, int team);
void changeValue(ScoreOBJ *scoreObj);
void endGame(ScoreOBJ *scoreObj);
void restart(ScoreOBJ *scoreObj);
void rollbackScore(ScoreOBJ *scoreObj);
void changeEndGameScore(ScoreOBJ *scoreObj, int value);

#endif //!__SCORE_FUNCTIONS__H__