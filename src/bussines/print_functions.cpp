#include "print_functions.h"


int seven_seg_digits[10][4] = {
    {0, 0, 0, 0}, // = 0
    {0, 0, 0, 1}, // = 1
    {0, 0, 1, 0}, // = 2
    {0, 0, 1, 1}, // = 3
    {0, 1, 0, 0}, // = 4
    {0, 1, 0, 1}, // = 5
    {0, 1, 1, 0}, // = 6
    {0, 1, 1, 1}, // = 7
    {1, 0, 0, 0}, // = 8
    {1, 0, 0, 1}  // = 9
};

void printValues(ScoreOBJ *scoreObj)
{
    Serial.println("Atualização de placar");
    Serial.println("Valor Score 1");
    Serial.println(scoreObj->score1);
    Serial.println("Valor Score 2");
    Serial.println(scoreObj->score2);
    Serial.println("Game Mode");
    Serial.println(scoreObj->game);
    Serial.println("Value");
    Serial.println(scoreObj->value);
    Serial.println("End game");
    Serial.println(scoreObj->endGameScore);
}

void updateSiftRegister()
{
  digitalWrite(STCP_pin, LOW);
  shiftOut(DS_pin, SHCP_pin, MSBFIRST, enviarBits);
  digitalWrite(STCP_pin, HIGH);
}