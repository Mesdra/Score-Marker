#include "print_functions.h"
#include "configs/config.h"

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
const Config config;

void updateSiftRegister(byte enviarBits, int stcp, int ds, int shcp)
{
    digitalWrite(stcp, LOW);
    shiftOut(ds, shcp, MSBFIRST, enviarBits);
    digitalWrite(stcp, HIGH);
}

void printValues(ScoreOBJ *scoreObj)
{
    byte display_1 = 0;
    byte display_2 = 0;
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

    if (config.display_on)
    {
        popularBitsScore1(&display_1, scoreObj->score1);
        popularBitsScore2(&display_2, scoreObj->score2);

        Serial.println("Valor Score 1 Binario");
        Serial.println(display_1, BIN);
        updateSiftRegister(display_1, config.STCP_SCORE1_pin, config.DS_SCORE1_pin, config.SHCP_SCORE1_pin);
        Serial.println("Valor Score 2 Binario");
        updateSiftRegister(display_2, config.STCP_SCORE2_pin, config.DS_SCORE2_pin, config.SHCP_SCORE2_pin);
        Serial.println(display_2, BIN);
    }
}
void blinkLed()
{
    Serial.println("Led acionado");
    if (config.display_on)
    {
        digitalWrite(config.BLINCK_pin, HIGH);
        delay(100);
        digitalWrite(config.BLINCK_pin, LOW);
    }
}

void popularBitsScore1(byte *display, int score)
{
    int v1 = 0;
    int v2 = 0;
    if (score >= 10)
    {
        v1 = score / 10;
        v2 = score % 10;
    }
    else
    {
        v2 = score;
    }
    popular(v2,v1,display);
}

void popularBitsScore2(byte *display, int score)
{
    int v1 = 0;
    int v2 = 0;
    if (score >= 10)
    {
        v1 = score / 10;
        v2 = score % 10;
    }
    else
    {
        v2 = score;
    }
    popular(v1,v2,display);
}

void popular(int desena,int sentena,byte *display){
    int cont = 3;
    for (size_t i = 0; i < 8; i++)
    {
        bitWrite(*display, i, seven_seg_digits[desena][cont]);
        if (cont == 0)
        {
            cont = 4;
            desena = sentena;
        }
        cont--;
    }
}