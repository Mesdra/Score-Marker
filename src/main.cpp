#include <Arduino.h>
#include "bussines/score_functions.h"
#include "model/scoreObj.h"
#include "configs/config.h"
#include "bussines/print_functions.h"
#include <IRremote.h>

const Config config;

ScoreOBJ *scoreObj;
IRrecv IR(config.IR_pin);

void setup()
{
  Serial.begin(9600);
  ScoreOBJ obj = {0, 0, 0, 0, 0, false, true};
  scoreObj = &obj;
  changeGameMode(scoreObj,2);
  IR.enableIRIn();

  pinMode(config.DS_SCORE1_pin, OUTPUT);
  pinMode(config.STCP_SCORE1_pin, OUTPUT);
  pinMode(config.SHCP_SCORE1_pin, OUTPUT);

  pinMode(config.DS_SCORE2_pin, OUTPUT);
  pinMode(config.STCP_SCORE2_pin, OUTPUT);
  pinMode(config.SHCP_SCORE2_pin, OUTPUT);
  
  pinMode(config.BLINCK_pin, OUTPUT);
  Serial.println(config.versao);
}

void loop()
{
  delay(100);

  // codigo contador score
  if (IR.decode())
  {
    blinkLed();
    uint32_t decodeDValue = IR.decodedIRData.decodedRawData;
    long value = decodeDValue;
    Serial.println(value);

    switch (value)
    {
    case -1320223231: // botão 1
      changeGameMode(scoreObj,1);
      break;
    case -233964031: // botão 2
      changeGameMode(scoreObj,2);
      break;
    case -217252351: // botão 3
      changeGameMode(scoreObj,3);
      break;
    case -1353646591: // botão seta esquerda
      addScore(scoreObj, 1);
      break;
    case -1370358271: // botão seta direita
      addScore(scoreObj, 2);
      break;
    case -334234111: // botão ok
      changeValue(scoreObj);
      break;
    case -417792511: // botão vol +
      subScore(scoreObj, 1);
      break;
    case -284099071: // botão vol -
      subScore(scoreObj, 2);
      break;
    case -434504191: // seta voltar
      restart(scoreObj);
      break;
    case -1136394751: // botão setup
      printValues(scoreObj);
      break;
    default:
      Serial.println("Nem uma ação foi tomada");
      break;
    }
    if (scoreObj->hasChanged)
    {
      printValues(scoreObj);
      endGame(scoreObj);
      scoreObj->hasChanged = false;
    }
    delay(config.tDelay);
    IR.resume();
  }
}
