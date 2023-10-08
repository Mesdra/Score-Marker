#ifndef __CONFIG__H__
#define __CONFIG__H__
#include <Arduino.h>
struct Config
{
  const int tDelay = 1000;         // defalt time delay
  const int DS_SCORE1_pin = 6;     // data pin
  const int STCP_SCORE1_pin= 7 ;   // clock
  const int SHCP_SCORE1_pin = 8;   // rck
  const int DS_SCORE2_pin = 9;     // data pin 
  const int STCP_SCORE2_pin= 10;   // clock
  const int SHCP_SCORE2_pin = 11;  // rck
  const int IR_pin = 3;            // RL Receiver pin
  const String versao = "Versão 0.0.3";     // project version
  const bool display_on = false;   // active display
};
#endif //!__CONFIG__H__