#include "score_functions.h"

void changeGameMode(ScoreOBJ *scoreObj)
{
    Serial.println("Moda de jogo Alterado");
    if (scoreObj->game == 3)
    {
        scoreObj->game = 0;
    }
    int gameMode = scoreObj->game + 1;
    Serial.println(gameMode);
    switch (gameMode)
    {
    case 1 /* basketball */:
        scoreObj->value = 2;
        scoreObj->endGameScore = 15;
        break;
    case 2 /* volleyball */:
        scoreObj->value = 1;
        scoreObj->endGameScore = 15;
        break;
    case 3 /* trick */:
        scoreObj->value = 1;
        scoreObj->endGameScore = 12;
        break;
    }
    scoreObj->score1 = 0;
    scoreObj->score2 = 0;
    scoreObj->game = gameMode;
    scoreObj->endGame = false;
    scoreObj->hasChanged = true;
};

void addScore(ScoreOBJ *scoreObj, int team)
{

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