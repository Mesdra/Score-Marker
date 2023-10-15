#include "score_functions.h"

void changeGameMode(ScoreOBJ *scoreObj, int gamemode)
{
    Serial.println("Modo de jogo Alterado");

    Serial.println(gamemode);
    switch (gamemode)
    {
    case 1 /* basketball */:
        Serial.println("basketball");
        scoreObj->value = 2;
        scoreObj->endGameScore = 15;
        break;
    case 2 /* volleyball */:
        Serial.println("volleyball");
        scoreObj->value = 1;
        scoreObj->endGameScore = 15;
        break;
    case 3 /* trick */:
        Serial.println("trick");
        scoreObj->value = 1;
        scoreObj->endGameScore = 12;
        break;
    }
    scoreObj->score1 = 0;
    scoreObj->score2 = 0;
    scoreObj->game = gamemode;
    scoreObj->endGame = false;
    scoreObj->hasChanged = true;
};

void addScore(ScoreOBJ *scoreObj, int team)
{

    Serial.println("value Add score ");
    Serial.println(scoreObj->value);
    Serial.println("score ");
    Serial.println(scoreObj->score1);
    if (team == 1)
    {
        scoreObj->score1 = scoreObj->score1 + scoreObj->value;
        scoreObj->hasChanged = true;
    }
    else if (team == 2)
    {
        scoreObj->score2 = scoreObj->score2 + scoreObj->value;
        scoreObj->hasChanged = true;
    }
    Serial.println("score ");
    Serial.println(scoreObj->score1);

    rollbackScore(scoreObj);
}

void rollbackScore(ScoreOBJ *scoreObj)
{

    switch (scoreObj->game)
    {
    case 1:
        scoreObj->value = 2;
        break;
    case 3:
        scoreObj->value = 1;
        break;
    }
}

void subScore(ScoreOBJ *scoreObj, int team)
{

    if (team == 1)
    {
        scoreObj->score1 = scoreObj->score1 - scoreObj->value;
        scoreObj->hasChanged = true;
    }
    else if (team == 2)
    {
        scoreObj->score2 = scoreObj->score2 - scoreObj->value;
        scoreObj->hasChanged = true;
    }

    rollbackScore(scoreObj);
}
void changeValue(ScoreOBJ *scoreObj)
{
    switch (scoreObj->game)
    {
    case 1:
        if (scoreObj->value == 2)
        {
            scoreObj->value = 3;
        }
        else if (scoreObj->value == 3)
        {
            scoreObj->value = 2;
        }
        scoreObj->hasChanged = true;
        break;
    case 3:
        if (scoreObj->value == 1)
        {
            scoreObj->value = 3;
        }
        else if (scoreObj->value == 3)
        {
            scoreObj->value = 6;
        }
        else if (scoreObj->value == 6)
        {
            scoreObj->value = 9;
        }
        else if (scoreObj->value == 9)
        {
            scoreObj->value = 12;
        }
        else if (scoreObj->value == 12)
        {
            scoreObj->value = 1;
        }
        scoreObj->hasChanged = true;
        break;
    }
}
void endGame(ScoreOBJ *scoreObj)
{
    if (scoreObj->score1 >= scoreObj->endGameScore || scoreObj->score2 >= scoreObj->endGameScore)
    {
        scoreObj->endGame = true;
        scoreObj->hasChanged = true;
        restart(scoreObj);
    }
};

void restart(ScoreOBJ *scoreObj)
{
    scoreObj->score1 = 0;
    scoreObj->score2 = 0;
    scoreObj->game = scoreObj->game;
    scoreObj->endGame = false;
    scoreObj->hasChanged = true;
};

void changeEndGameScore(ScoreOBJ *scoreObj, int value)
{
    scoreObj->endGameScore = value;
    scoreObj->hasChanged = true;
}