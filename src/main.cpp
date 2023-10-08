#include <Arduino.h>
#include "bussines/score_functions.h"
#include "model/scoreObj.h"
#include "bussines/print_functions.h"
#include <IRremote.h>

ScoreOBJ *scoreObj;
IRrecv IR(3);

const int tDelay = 1000;
const int DS_pin = 6;     // data pin
const int STCP_pin = 7;   // clock
const int SHCP_pin = 8;   // rck
const int BUTTON_pin = 9; // rck

int buttonState = 0;
int cont = 0;

byte enviarBits = 0;

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

void updateSiftRegister()
{
  digitalWrite(STCP_pin, LOW);
  shiftOut(DS_pin, SHCP_pin, MSBFIRST, enviarBits);
  digitalWrite(STCP_pin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  ScoreOBJ obj = {0, 0, 0, 0, 0, false, true};
  scoreObj = &obj;
  changeGameMode(scoreObj);
  IR.enableIRIn();

  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  pinMode(BUTTON_pin, INPUT);
  Serial.println("Versão 0.0.3");
}

void loop()
{
  delay(100);
  buttonState = digitalRead(BUTTON_pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
    // turn LED on:
    Serial.println("Enviando valor para display");
    Serial.println(cont);
    enviarBits = 0;
    bitWrite(enviarBits, 0, seven_seg_digits[cont][3]);
    bitWrite(enviarBits, 1, seven_seg_digits[cont][2]);
    bitWrite(enviarBits, 2, seven_seg_digits[cont][1]);
    bitWrite(enviarBits, 3, seven_seg_digits[cont][0]);
    bitWrite(enviarBits, 4, seven_seg_digits[cont][3]);
    bitWrite(enviarBits, 5, seven_seg_digits[cont][2]);
    bitWrite(enviarBits, 6, seven_seg_digits[cont][1]);
    bitWrite(enviarBits, 7, seven_seg_digits[cont][0]);
    Serial.print(enviarBits, BIN);
    updateSiftRegister();
    delay(tDelay);
    if (cont == 9)
    {
      cont = 0;
    }
    else
    {
      cont++;
    }
  }

  // codigo contador score
  // if (IR.decode())
  // {
  //   uint32_t decodeDValue = IR.decodedIRData.decodedRawData;
  //   long value = decodeDValue;
  //   Serial.println(value);

  //   switch (value)
  //   {
  //   case -1136394751: // botão setup
  //     changeGameMode(scoreObj);
  //     break;
  //   case -1353646591: // botão seta esquerda
  //     addScore(scoreObj, 1);
  //     break;
  //   case -1370358271: // botão seta direita
  //     addScore(scoreObj, 2);
  //     break;
  //   case -334234111: // botão ok
  //     changeValue(scoreObj);
  //     break;
  //   case -417792511: // botão vol +
  //     subScore(scoreObj, 1);
  //     break;
  //   case -284099071: // botão vol -
  //     subScore(scoreObj, 2);
  //     break;
  //   case -434504191:
  //     restart(scoreObj);
  //     break;
  //   default:
  //     Serial.println("Nem uma ação foi tomada");
  //     break;
  //   }
  //   if (scoreObj->hasChanged)
  //   {
  //     printValues(scoreObj);
  //     endGame(scoreObj);
  //     scoreObj->hasChanged = false;
  //   }
  //   delay(1500);
  //   IR.resume();
  // }
}
